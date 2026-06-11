#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll h,w;
    cin>>h>>w;

    ll ans=w*(h/2);
    if(h%2==1)ans+=(w+1)/2;

    if(h==1||w==1) cout<<"1\n";
    else cout<<ans<<"\n";

    return 0;
}
