#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  int n, ans = 0, idx;
  cin >> n >> s;
  idx = s.find("ABC");
  while(idx != string::npos)
  {
    ans++;
    s = s.substr(idx+1);
    idx = s.find("ABC");
  }
  cout << ans << endl;
  return 0;
}