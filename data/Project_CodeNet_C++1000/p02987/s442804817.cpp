#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  string s; cin >> s;
  map<char, int> ma;
  rep(i, s.size())
  {
    ma[s[i]]++;
  }
  bool f = true;
  for (auto it : ma)
  {
    if (it.second != 2)
    {
      f = false;
      break;
    }
  }
  if (f) cout << "Yes" << endl;
  else cout << "No" << endl;
}