#include <bits/stdc++.h>

using namespace std;

#define ll  long long
#define f first
#define s second

const int N = 1e6+5;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    ll a,b,c,d,ans=-2e18;
    cin >> a >> b >> c >> d;

    if (b >= 0 && a <= 0) ans=0;
    if (d >= 0 && c <= 0) ans=0;

    //mx pos
    ans = max(ans , b*d);

    //mx neg
    ans = max(ans , a*c);

    //mn neg
    if (b < 0 && c > 0)
    {
        ans = max(ans , b*c);
    }
    if (d < 0 && a > 0)
    {
        ans = max(ans , a*d);
    }

    cout << ans << '\n';

    return 0;
}