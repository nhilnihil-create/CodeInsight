#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  
  string s[n];
  string t;
  rep(i,n)
  {
    cin >> t;
    sort(t.begin(),t.end());
    s[i] = t;
  }
  
  sort(s,s+n);
  
  ll x[n] = {0};
  for(int i = 1; i < n; i++)
  {
    if(s[i] == s[i-1])
    {
      x[i] += x[i-1] + 1;
    }else
    {
      x[i] = 0;
    }
  }
  
  ll ans = 0;
  for(int i = 0; i < n; i++)
  {
    ans += x[i];
  }
  
  cout << ans << endl; 
  
}
