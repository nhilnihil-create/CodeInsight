#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i) 
typedef long long ll;
using namespace std;

int main(){
  ll t1,t2; cin >> t1 >> t2;
  ll a1,a2; cin >> a1 >> a2;
  ll b1,b2; cin >> b1 >> b2;

  ll c1=t1*a1; ll d1=t1*b1;
  ll c2=t2*a2; ll d2=t2*b2;
  
  ll B1=max(c1,d1); ll B2=max(c2,d2);
  ll S1=min(c1,d1); ll S2=min(c2,d2);
  ll s1=B1-S1; ll s2=B2-S2;
  ll ans=0; ll cs=s1;
  
  if( ( (c1>d1) && (c2>d2) ) || ( (c1<d1) && (c2<d2) ) ) cout << 0 << endl;
  else{
  if(s1<s2){
    cs=s2-s1;
    ans+=(s1/cs)*2;
    s1=s1-((ans/2)*cs);
    if(s1==0) cout << ans << endl;
    else cout << ans+1 << endl;
  }
  else if(s1==s2) cout << "infinity" << endl;
  else cout << 0 << endl;
  }
 return 0;
}
