#include <bits/stdc++.h>
using ll= long long ;
#define rep(i,n) for (ll i = 0; i<(ll)(n); i++)
using namespace std;
using P = pair<ll,ll>;
ll gcd(ll a,ll b){
    if(b>a) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}
ll lcm(ll a, ll b){
    ll g=gcd(a,b);
    return a/g*b;
}

int main() {
   ll a,b,c;
   cin>>a>>b>>c;
   ll d = a*a+b*b+c*c-2*a*b-2*a*c-2*c*b;
if(d>0 && c > a+b ){
    cout<<"Yes"<<endl;
}
else{
    cout<<"No"<<endl;
}
    return 0;
}