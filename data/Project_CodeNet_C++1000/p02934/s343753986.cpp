/*
 *  Author : Tatsuhiro Hashimoto
 *  Created : Thu Jun 11 19:34:37 JST 2020
 */
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FSP(n, v) cout << fixed << setprecision(n) << (v) << endl;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define iMAX 2147483647;
#define lMAX 9223372036854775807;
#define llMAX 18446744073709551615;
#define SORT(v) sort((v).begin(), (v).end());
#define REV(v) reverse((v).begin(), (v).end());
static inline ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b);}
static inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
#define prepare cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

ld ans = 0.0;

void solve() {
    int N; cin >> N;
    vector<int> A(N, 0);
    ll lcm_v = 0, c_sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (i == 0) lcm_v = A[i];
        else lcm_v = lcm(lcm_v, A[i]);
    }
    for (int i = 0; i < N; ++i) {
        c_sum += lcm_v / A[i];
    }
    ans = (long double)(lcm_v / (c_sum * 1.0));
}

signed main() {
    prepare
    solve();
    FSP(6, ans)
}