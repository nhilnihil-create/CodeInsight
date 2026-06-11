#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll a,b,c,d; cin>>a>>b; c=min(a,b); d=max(a,b);
    ll l=__gcd(c,d);
    ll r=(a*b);
    cout<<r/l;
}
