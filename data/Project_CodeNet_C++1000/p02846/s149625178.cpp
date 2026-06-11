#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  ll t1, t2;
  ll a1, a2;
  ll b1, b2;
  cin>>t1>>t2>>a1>>a2>>b1>>b2;
  a1 *= t1; a2 *= t2;
  b1 *= t1; b2 *= t2;
  ll p = a1 - b1;
  ll q = a2 - b2;
  if(p<0)p = -p,q = -q;
  ll pq = p+q;
  if(pq==0){
    cout << "infinity" << endl;
    return 0;
  }else if(pq>0){
    cout << 0 << endl;
    return 0;
  }else{
    ll ans;
    ans = (p/(-pq))*2+1;
    if(p%(-pq)==0)ans -= 1;
    cout << ans << endl;
    return 0;
  }
}
