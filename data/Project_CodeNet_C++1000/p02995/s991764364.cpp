#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll e=c*d/__gcd(c,d);
    ll cnt1=b/c,cnt2=b/d,cnt3=b/e;
    if(a%c==0)
        cnt1-=(a/c-1);
    else
        cnt1-=a/c;
    if(a%d==0)
        cnt2-=(a/d-1);
    else
        cnt2-=(a/d);
    if(a%e==0)
         cnt3-=(a/e-1);
    else
        cnt3-=a/e;
    cout<<(b-a+1)-(cnt1+cnt2-cnt3);
    return 0;

}