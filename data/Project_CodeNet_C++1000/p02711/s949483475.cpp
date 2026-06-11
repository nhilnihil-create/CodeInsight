#include <iostream>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  bool find = false;
  cin >> s;
  for (int i = 0; i < 3; i++)
    if (s[i] == '7')
      find = true;
  cout << (find? "Yes" : "No") << '\n';
  return 0;
}
