#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
int main()
{
    ll s;
    cin >> s;
    ll x1 = 0, y1 = 0;
    ll x2 = 1e9, y2 = 1;
    ll x3,y3;
    if(s >= 1e9){
        y3 = (s+x2-1) / x2;
        x3 = abs(s - y3 * x2);
    }
    else
    {
        y3 = 0;
        x3 = s;
    }
    printf("%lld %lld %lld %lld %lld %lld", x1, y1, x2, y2, x3, y3);
}