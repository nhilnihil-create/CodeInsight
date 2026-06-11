#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e6+233;

int main(){
    
    ll x,k,d;
    cin>>x>>k>>d;
    ll ans;
    x = abs(x);
    ll s = min(k,x/d);
    k-=s;
    x-=s*d;
    if(k&1) cout<<d-x<<endl;
    else cout<<x<<endl;
    
    return 0;
}