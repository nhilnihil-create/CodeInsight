#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll x, y;
    cin>>x>>y;
    ll g = __gcd(x, y);
    // cout<<"gcd is "<<g<<endl;
    ll ans = 1;
    // cout<<1<<endl;
    ll temp = g;
    for (ll i = 2; i<=sqrt(g); i++){
        if (temp%i==0){
            // cout<<i<<endl;
            ans++;
            while(temp%i==0)temp/=i;
        }
        if (temp == 1)break;
    }
    if (temp > 1)ans++;
    cout<<ans<<endl;
}