#include <iostream>
using namespace std;

int main()
{

  string name;
  getline(cin, name);

  if(name[2]== name[3] && name[4] == name[5])
  {
    cout << "Yes" << endl;
  }
  else
  cout << "No" << endl;
}
