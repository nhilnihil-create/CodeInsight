#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll a,b,c;cin>>a>>b>>c;

    ll f=4*a*b;

    ll d=c-a-b;

    bool ans=d>0&&d*d>f;

    puts(ans?"Yes":"No");

    return 0;
}
