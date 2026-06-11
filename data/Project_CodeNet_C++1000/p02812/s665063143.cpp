#include <iostream>
#include <string>

using namespace std;

int main()
{
  int n; cin >> n;
  string s; cin >> s;
  int cnt = 0;
  for (int i = 0; i < (int)s.size() - 2; i++)
    if (s.substr(i, 3) == "ABC") cnt++;
  cout << cnt << endl;
}