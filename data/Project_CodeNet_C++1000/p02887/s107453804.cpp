#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  string s;
  cin >> n >> s;
  vector<char> ans;
  for (int i = 0; i < n - 1; i++)
  {

    if (s[i] == s[i + 1])
    {
      continue;
    }
    else
    {
      ans.push_back(s[i]);
    }
  }
  ans.push_back(s[n - 1]);

  cout << ans.size() << endl;
}
