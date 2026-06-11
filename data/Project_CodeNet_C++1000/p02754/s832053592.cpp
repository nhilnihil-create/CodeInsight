#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n,a,b;
    cin>>n>>a>>b;
    ll ans = n/(a+b) *a;
    ll remainder = n%(a+b);
    if( remainder >= a)
        ans+=a ;
    else ans+= remainder;
    cout<<ans;
}