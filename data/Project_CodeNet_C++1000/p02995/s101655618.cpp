#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

ll gcd(ll n, ll m){
  if(n < m) swap(n,m);

  if(m==0) return 0;
  while(m > 0){
    ll res = n%m;
    n = m;
    m = res;
  }
  return n;
}

ll lcm(ll n, ll m){
  return m*n/gcd(n,m);
}


int main(){
  ll a,b,c,d;
  cin >> a >> b >> c >> d;

  ll c_cnt = b/c-(a-1)/c;
  ll d_cnt = b/d-(a-1)/d;
  ll cd_cnt = b/lcm(c,d)-(a-1)/lcm(c,d);
  ll ans = (b-a+1) - c_cnt - d_cnt + cd_cnt;
  cout << ans << endl;
  
}
