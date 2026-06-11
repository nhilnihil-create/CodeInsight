#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
#define pb push_back
#define PI 3.14159265
int M = 998244353;
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == '?')
      s[i] = 'D';
  }
  cout << s;

}