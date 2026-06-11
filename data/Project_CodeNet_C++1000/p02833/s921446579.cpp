#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin>>n;
    if (n<2 || n&1){
        cout<<0<<endl;
        return 0;
    }
    ll k = 10;
    ll ans = 0;
    while(1){
        ll x = n/k;
        if (x==0)break;
        ans += x;
        k = k*5;
    }
    // k=50;
    // while(1){
    //     ll x = n/k;
    //     if (x==0)break;
    //     ans += x;
    //     k = k*50;
    // }
    cout<<ans<<endl;
}