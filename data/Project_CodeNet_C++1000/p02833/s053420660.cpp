#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

ll prime5(const ll n)
{
    ll ans = 0;
    for (ll value = 5; value <= n; value *= 5)
        ans += n / (value * 2);
    return ans;
}

int main()
{
    ll n;
    cin >> n;

    if (n % 2 == 1)
        cout << 0 << endl;
    else
        cout << prime5(n) << endl;
}