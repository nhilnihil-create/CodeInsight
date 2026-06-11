#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, a, n) for (ll i = a; i < (ll)n; ++i)
const ll MOD = 1000000007;
using namespace std;

int main(void)
{
    ll n;
    cin >> n;
    ll ans = 1;
    while (ans <= n)
        ans *= 2;

    cout << (ans / 2) * 2 - 1 << endl;
}
