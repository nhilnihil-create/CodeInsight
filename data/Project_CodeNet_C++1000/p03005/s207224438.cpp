#include <iostream>
using namespace std;

int main()
{
  int ball, people;

  cin >> ball >> people;

  if(people != 1)
  {
    cout << ball - people << endl;
  }
  else
  cout << 0 << endl;
}
