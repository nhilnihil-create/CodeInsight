#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll f(ll n,ll x){
    if(n>=0)
    return n/x+1;
    else
    return 0;
}
ll gcd(ll a,ll b){
	if(!b)return a;
	return gcd(b,a%b);
}
int main(){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll lcm=(c*d)/gcd(c,d);
    ll dc=f(b,c)-f(a-1,c);
    ll dd=f(b,d)-f(a-1,d);
    ll l=f(b,lcm)-f(a-1,lcm);
    cout<<(b-a)-(dc+dd-l)+1;
}