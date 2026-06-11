#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N, M;
vector<ll> a;

// 2で何回割り切れるか
ll f(ll x) {
    ll cnt = 0;
    while (x % 2 == 0) {
        x /= 2;
        cnt++;
    }
    
    return cnt;
}

// 最大公約数
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

// 最小公倍数
ll lcm(ll a, ll b) { return a / gcd(a,b) * b; }

int main() {
    cin >> N >> M;
    a.resize(N);
    rep(i, N) cin >> a[i];

    rep(i, N) a[i] /= 2;

    ll t = f(a[0]);

    for (int i = 0; i < N; i++) {
        ll b = f(a[i]);

        // 2の素因数の数が違う場合、ありえない
        if (t != b) {
            cout << 0 << endl;
            return 0;
        }

        a[i] <<= t;
    }
    M <<= t;

    // lcm を求める
    ll val = 1;
    for (int i = 0; i < N; i++) {
        val = lcm(val, a[i]);
    }

    // 計算 偶数は省く
    ll ans = ((M / val) + 1) / 2;
    cout << ans << endl;
}