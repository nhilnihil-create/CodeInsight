#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;

#define PIE acos(-1);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    ld a,b,x;
    cin >> a >> b >> x;
    ld half=(pow(a,2)*b)/2;

    ld ans;
    if (x<half)
    {
        ans=atan2(a*pow(b,2),2*x);
    }
    else
    {
        ld alpha=(pow(a,2)*b)-x;
        ans=atan2(2*alpha,pow(a,3));
    }
    ans=(ans*180.0)/PIE;
    cout << ans << endl;

    return 0;
}