#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
 
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, D, A;
    cin >> N >> D >> A;
    vector<P> p(N);
    REP(i, N) {
        cin >> p[i].first >> p[i].second;
    }
    VSORT(p);
    vll x(N), h(N);
    REP(i, N) {
        x[i] = p[i].first, h[i] = p[i].second;
    }
    ll res = 0;
    vll mem(N + 1); // mem[i] : i に既に入った爆破回数
    REP(i, N) {
        mem[i + 1] += mem[i];
        // 体力を削りきっていたら continue
        h[i] -= mem[i] * A;
        if (h[i] <= 0) continue;
        ll b = (h[i] - 1) / A + 1; // ここで必要な爆破回数
        res += b;
        mem[i + 1] += b;
        ll ub = upper_bound(ALL(x), x[i] + 2 * D) - x.begin();
        mem[ub] -= b;
    }
    cout << res << endl;
    return 0;
}