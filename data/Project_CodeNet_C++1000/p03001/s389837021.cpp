#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define Q int tt,qq; cin>>tt ;for(qq=1;qq<=tt;qq++)
#define I ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int main()
{
    double a,b,x,y;
    cin>>a>>b>>x>>y;
    cout<<(a*b)/2<<" ";
    if(x==a/2&&y==b/2)cout<<1;
    else cout<<0;
}
