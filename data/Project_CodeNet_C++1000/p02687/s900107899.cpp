#include <iostream>
using namespace std;

void ac()
{
  string contest;

  getline(cin, contest);
  while(contest != "ARC" && contest != "ABC")
  {
    getline(cin, contest);
  }

  if(contest == "ARC")
  {
    cout << "ABC" << endl;
  }

  else
  {
    cout << "ARC" << endl;
  }


}
  int main()
  {
    ac();
  }
