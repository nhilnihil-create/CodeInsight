#include <bits/stdc++.h>

using namespace std;
#define  ll long long
#define ld long double
#define f first
#define s second


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll w,h,x,y,ar,ans=0,c=0;
    cin >> w >> h >> x >> y;

    /*
    ar = w*h;
    if (x != 0 && x<w)
    {
        ll tmp = h*x;
        ans = min(tmp , ar-tmp);
    }

    if (y != 0 && y < h)
    {
        ll tmp = w*y;
        if (min(tmp,ar-tmp) == ans) c=1;
        ans = max(ans , min(tmp,ar-tmp));
    }

    if (ans==0) cout << fixed << setprecision(10) << (ld)ar/2 << ' ' << 0 << '\n';
    else
    cout << fixed << setprecision(10) << (ld)ans << ' ' << c << '\n';
     */

    ar = w*h;
    cout << fixed << setprecision(10) << (ld)ar/2 << ' ' << (x*2==w && y*2==h) << '\n';


    return 0;
}