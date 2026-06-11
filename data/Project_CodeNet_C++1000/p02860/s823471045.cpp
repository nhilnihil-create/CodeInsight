#include <iostream>
using namespace std;

int main()
{
  int n;
  string s;
  cin >> n >> s;
  string subs = s.substr(0, n / 2);
  if(s == (subs + subs))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}