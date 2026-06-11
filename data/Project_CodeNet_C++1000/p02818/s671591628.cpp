#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    ll a, b, k;
    cin >> a >> b >> k;
    ll r = min(a, k);
    a -= r;
    k -= r;
    r = min(b, k);
    b -= r;
    k -= r;
    printf("%lld %lld\n", a, b);
    return 0;
}