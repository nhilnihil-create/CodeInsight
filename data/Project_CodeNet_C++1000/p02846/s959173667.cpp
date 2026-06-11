#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define sz(x) ll(x.size())
using namespace std;

int main() {
  ll ans=0,t1,t2,a1,a2,b1,b2,p,q,s,t;
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
  p=(a1-b1)*t1;
  q=(a2-b2)*t2;
  if(p>0) {
  	p*=-1; q*=-1;
  }
  if(p+q<0) puts("0");
  else if(p+q==0) puts("infinity");
  else{
  	s=-p/(p+q);
  	t=-p-(p+q)*s;
  	ans+=s*2;
  	if(t!=0) ans++;
    cout << ans << endl;
  }
}
