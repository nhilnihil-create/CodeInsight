#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 2つの整数の場合
long long GetGreatestCommonDivisor(long long a, long long b)
{
    long long m = a;
    long long n = b;
    long long temp;
    while (m % n != 0) {
        temp = n;
        n = m % n;
        m = temp;
    }
    return n;
}

int main() {

    ll k; cin >> k;
    ll ans = 0;
    for (ll i = 1; i <= k; i++) {
        for (ll j = 1; j <= k; j++) {
            for (ll x = 1; x <= k; x++) {
                vector<ll> c;
                c.push_back(i);
                c.push_back(j);
                c.push_back(x);
                // 3つ以上の整数の場合
                long long gcd = c[0];
                for (int z = 0; z < c.size(); z++) {
                    gcd = GetGreatestCommonDivisor(gcd, c[z]);
                }
                ans += gcd;
            }
        }
    }
    cout << ans << endl;
    return 0;
}