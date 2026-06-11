#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  ll n,k,q;
  cin >> n >> k >> q;
  
  ll a[q];
  rep(i,q) cin >> a[i];
  
  ll ans[n];
  rep(i,n) ans[i] = 0;
  
  rep(i,q)
  {
    ans[a[i]-1]++;
  }
  
  rep(i,n)
  {
    if(k + ans[i] > q)
    {
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
}