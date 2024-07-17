#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

void printMenu();

int main()
   {

       int input1 = 0;
       string inputInfo;
       string projectName;
       int numberOfParticipants, count;
       string line;
       bool success = false;


       LinkedList * list1 = new LinkedList();

       printMenu();


       do
        {
           cout << "\nChoose your option: \n";
           cin >> input1;
           cin.ignore(20, '\n');
           switch (input1)
            {
             case 1:
                cout << "\nEnter a project name:\n";
                getline(cin, projectName);

                cout << "Enter a number of members:\n";
                cin >> count;
                cin.ignore(20, '\n');

                success = list1->addProject(projectName, count);

                if (success == true)
                 cout << "The project " << projectName << " added\n";
                else
                 cout << "The project " << projectName << " not added\n";
                break;
             case 2:
                 cout << "\n";
                list1->printList();
                break;
             case 3:
                cout << "\nPlease enter a project name to change its member count:\n";
                getline(cin, projectName);

                cout << "Enter a number of its participants:\n";
                cin >> count;
                cin.ignore(20, '\n');

                success = list1->changeParticipantNumber(projectName, count);
                if (success == true)
                        cout << "The project " << projectName << " updated\n";
                else
                        cout << "The project " << projectName << " does not exist\n";
                break;
             case 4:
                cout << "\nPlease enter a project name to remove:\n";
                getline(cin, projectName);

                success = list1->removeProject(projectName);
                if (success == true)
                 cout << "The project " << projectName << " removed\n";
                else
                 cout << "The project " << projectName << " does not exist\n";
                break;
             case 5:
                printMenu();
                break;
             case 6:
                delete list1;
                break;
             default:
                cout << "Unknown action\n";
                break;
            }

        } while (input1 != 6);

      return 0;
   }



  void printMenu()
   {
     cout << "======= Member Project Management System =======\n\n";
     cout << "=>1 Create Project\n";
     cout << "=>2 Display Projects\n";
     cout << "=>3 Update Member\n";
     cout << "=>4 Remove Project\n";
     cout << "=>5 Back to Main Menu\n";
     cout << "=>6 Quit Application\n";
  }


