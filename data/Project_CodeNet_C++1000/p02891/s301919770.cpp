#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;

int main()
{
  string s;
  ll k;
  cin >> s >> k;
  int n = s.size();
  
  vector<int> cnt = {1};
  for(int i = 1; i < n; i++)
  {
    if(s[i] == s[i - 1])
    {
      cnt.back()++;
    }
    else
    {
      cnt.emplace_back(1);
    }
  }
  //for(auto x : cnt) cout << x << " "; cout << endl;
  
  if((int)cnt.size() == 1)
  {
    k *=  cnt[0];
    cout << k / 2 << endl;
    return 0;
  }
  
  if(s[0] != s[n - 1] || k == 1)
  {
    ll a = 0;
    for(auto x : cnt)
    {
      a += x / 2;
    }
    cout << k * a << endl;
  }
  else
  {
    ll a = 0, ans = 0;
    
    //prefixとsuffix
    for(int i = 0; i < cnt.size(); i++)
    {
      ans += cnt[i] / 2;
    }
    
    //あいだの部分
    cnt[0] += cnt.back();
    for(int i = 0; i + 1 < cnt.size(); i++)
    {
      a += cnt[i] / 2;
    }
    ans += (k - 1) * a;
    cout << ans << endl;
  }
  
  return 0;
}