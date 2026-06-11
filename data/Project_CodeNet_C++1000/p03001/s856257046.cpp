#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll w,h;cin>>w>>h;
    ll x,y;cin>>x>>y;

    double s=w*h/2.0;
    int m=0;
    if(x*2==w&&y*2==h)m=1;

    printf("%.10lf %d",s,m);

    return 0;
}
