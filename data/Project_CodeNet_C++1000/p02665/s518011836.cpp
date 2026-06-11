#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<ll> a(n+1);
  vector<ll> sum(n+1,0);
  rep(i,n+1) cin >> a[i];
  sum[n] = a[n];
  for(int i = n-1; i>=0; i--){
    sum[i] = a[i] + sum[i+1];
  }
  ll pre = 0;
  ll ans = 0;
  ll rest = 0;
  rep(i,n+1){
    ll v = min(rest *2, (ll) 5e13);
    if(i==0) v = 1;
    // ll tmp = rest*2;
    // if(i==0) tmp = 0;
    // ll mu = 2;
    // ll v = 1;
    // while(tmp>0){
    //   if(mu>5e13 || v > 5e13){
    //     v = 5e13+1;
    //     break;
    //   }
    //   if(tmp&1){
    //     v *= mu;
    //   }
    //   tmp >>= 1;
    //   mu*=mu;
    // }
    if(a[i] > v){
      cout << -1 << endl;
      return 0;
    }
    rest = v - a[i];
    ans += min(v,sum[i]);
    // cout << ans << endl;
  }
  // }
  // for(int i = n; i>=0; i--){
  //   int tmp = i;  
  //   ll mu = 2;
  //   ll v = 1;
  //   while(tmp>0){
  //     if(mu>5e13 || v > 5e13){
  //       v = 5e13+1;
  //       break;
  //     }
  //     if(tmp&1){
  //       v *= mu;
  //     }
  //     tmp >>= 1;
  //     mu*=mu;
  //   }
  //   ll cmin = pre/2 + a[i];
  //   ll cmax = pre + a[i];
  //   if(cmin > v){
  //     cout << -1 << endl;
  //     return 0;
  //   }
  //   ans += min(cmax,v);
  //   pre = min(cmax,v);
  //   cout << pre << " " << v << endl;
  // }
  cout << ans << endl;
  return 0;
    

}
