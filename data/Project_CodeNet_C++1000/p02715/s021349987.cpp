#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll a, ll n)
{
    ll s = 1;
    while(n) s = s * ((n % 2) ? a : 1) % 1000000007, a = a * a % 1000000007, n >>= 1;
    return s;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //Input
    ll n, k;
    cin >> n >> k;
    ll sum = 0;

    vector<ll> a(k + 1);
    for(int i = k; i > 0; i--)
    {
        a[i] = solve(k / i, n);
        for(int j = i * 2; j <= k; j += i)
        {
            a[i] -= a[j];
        }
        a[i] = (a[i] % 1000000007 + 1000000007) % 1000000007;
        sum += i * a[i];
    }

    cout << sum % 1000000007 << "\n";
}
