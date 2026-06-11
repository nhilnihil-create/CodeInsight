#include <iostream>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  string str;
  cin >> str;
  cout << ((str[2] == str[3] && str[4] == str[5])? "Yes" : "No") << '\n'; 
  return 0;
}
