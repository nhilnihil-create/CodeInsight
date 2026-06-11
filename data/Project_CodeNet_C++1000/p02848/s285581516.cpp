#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  int n; cin >> n;
  string s; cin >> s;
  vector<char> vc(s.size());
  for (int i = 0; i < s.size(); i++)
  {
    char ci = s[i];
    int m = n;
    if (ci + m > 'Z') m -= 26;
    vc[i] = (char)((ci+m));
  }
  for (auto c : vc) cout << c;
  cout << endl;
}