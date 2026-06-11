#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  string s, t;
  cin >> n >> s >> t;
  vector<char> ans;
  for (int i = 0; i < n; i++)
  {
    ans.push_back(s[i]);
    ans.push_back(t[i]);
  }
  for (int i = 0; i < 2 * n; i++)
  {
    cout << ans[i];
  }
  cout << endl;
}
