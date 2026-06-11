#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  ll n, a, b;
  cin >> n >> a >> b;
  ll d = b - a;
  ll ans;
  if(d % 2 == 0){
    ans = d/2;
  }else{
    ll a1 = (a-1) + 1;
    a1 += (d-1)/2;
    ll a2 = (n-b) + 1;
    a2 += (d-1)/2;
    ans = min(a1, a2);
  }
  cout << ans << endl;
  return 0;
}