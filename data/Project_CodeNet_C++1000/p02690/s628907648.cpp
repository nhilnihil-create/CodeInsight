#include<bits/stdc++.h>
using ll=long long;
using namespace std;
int main(void){
  int x; cin>>x;
  int q=sqrtl(sqrtl(x));
  for(ll a=-q; abs(a)<=q; ++a) for(ll b=-q; abs(b)<=q; ++b) if(a*a*a*a*a-b*b*b*b*b==x){ printf("%lld %lld\n",a,b); return 0;}
  return 0;
}
