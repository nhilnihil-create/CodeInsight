#include<bits/stdc++.h>
using namespace std;

#define ll signed long long
ll x,y,a,b,c,d;
int main()
{
    scanf("%lld %lld %lld %lld",&a, &b, &c, &d);
    ll ans = max(a*c, b*c);
    ans = max(ans,a*d);
    ans = max(ans,b*d);
    cout << ans;
    return 0;
}
