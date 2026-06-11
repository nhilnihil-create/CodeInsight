#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main()
{
  string s,t; cin >> s >> t;
  int cnt=0;
  for(int i = 0; i<s.length(); ++i)
  {
    if(s[i]!=t[i]) ++cnt;
  }
  cout << cnt << endl;
}