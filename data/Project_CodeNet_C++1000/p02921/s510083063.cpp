#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  int ans = 0;
  string s,t;
  cin >> s >> t;
  if(s[0] == t[0])ans++;
  if(s[1] == t[1])ans++;
  if(s[2] == t[2])ans++;
  cout << ans;
}