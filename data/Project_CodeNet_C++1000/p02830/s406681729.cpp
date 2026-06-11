#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  rep(i, n)
    cout << s[i] << t[i];
  puts("");
  return 0;
}