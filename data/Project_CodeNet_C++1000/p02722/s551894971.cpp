// 6/18 振り返り
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

// 約数列挙
vector<ll> divisor(ll n) {
    vector<ll> res;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i * i != n) res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    ll N;
    cin >> N;

    ll ans = 0;

    // N-1の約数は全て条件を満たす。
    vector<ll> div1 = divisor(N - 1);
    ans += div1.size() - 1;  // 1の場合だけ引いておく。

    // Nの約数のうち、割れるだけ割った後にmod kが1だったらOK。
    vector<ll> div2 = divisor(N);
    for (auto d : div2) {
        if (d == 1) continue;

        ll n = N;
        while (n % d == 0) {
            n /= d;
        }

        if (n % d == 1) {
            ans++;
        }
    }

    cout << ans << endl;
}