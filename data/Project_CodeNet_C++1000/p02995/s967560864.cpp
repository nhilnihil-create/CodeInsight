#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll gcd (ll a,ll b){
  if(a%b==0){
    return b;
  }
  else{
    return gcd(b,a%b);
  }
}
int main(){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll x=b/c-(a-1)/c;
    ll y=b/d-(a-1)/d;
    ll z=gcd(c,d);
    ll zz=c*d/z;
    ll zzz=b/zz-(a-1)/zz;
    ll www =(b-a+1)-(x+y-zzz);
    cout<<www<<endl;
    return 0;
}


