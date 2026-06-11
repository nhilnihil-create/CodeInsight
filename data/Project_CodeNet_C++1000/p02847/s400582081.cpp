#include <iostream>
#include <map>
using namespace std;

string week[7] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
map<string, int> weekmap;

void CreateWeekMap()
{
  for(int i = 7; i > 0; i--)
    weekmap[week[7 - i]] = i;
}

int main()
{
  string S;
  cin >> S;
  CreateWeekMap();
  cout << weekmap[S] << endl;
  return 0;
}