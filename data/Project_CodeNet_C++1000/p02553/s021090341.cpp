#include <stdio.h>
#include <string.h>
#include <iostream>
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;
const int MAXN=1100;
int main()
{
    ios;
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll ans[5];
    ans[1]=a*c;
    ans[2]=a*d;
    ans[3]=b*c;
    ans[4]=b*d;
    ll x=max(ans[1],ans[2]);
    ll y=max(ans[3],ans[4]);
    cout<<max(x,y)<<'\n';
    return 0;
}