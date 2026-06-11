#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll h;
    cin>>h;

    int cnt=0;
    while(h!=1)
    {
        h/=2;
        cnt++;
    }

    ll ans=pow(2,cnt+1)-1;

    cout<<ans<<"\n";

    return 0;
}
