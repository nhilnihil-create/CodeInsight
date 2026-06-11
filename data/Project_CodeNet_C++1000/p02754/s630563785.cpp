#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

constexpr int mod = 998244353;

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;

    ll d = n / (a + b);
    ll r = n % (a + b);
    cout << a * d + min(r, a) << endl;
}