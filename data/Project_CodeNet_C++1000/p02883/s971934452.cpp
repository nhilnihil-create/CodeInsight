#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
#define ALL(v) v.begin(), v.end()
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define chmax(x, a) x = max(x, a)
#define chmin(x, a) x = min(x, a)

int main() {
    ll N, K; cin >> N >> K;
    vector<ll> A(N), F(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> F[i];
    sort(ALL(A)); sort(ALL(F));
    vector<pair<ll, ll>> memo(N);
    rep(i, N) memo[i] = make_pair(A[i]*F[N-i-1], i);
    sort(ALL(memo));
    reverse(ALL(memo));
    ll ok = memo[0].first, ng = -1;
    while (abs(ok-ng) > 1) {
        ll mid = (ok+ng)/2;
        ll cnt = 0;
        bool flag = true;
        rep(i, N) {
            if (memo[i].first <= mid) break;
            ll tmp = memo[i].second;
            cnt += A[tmp] - mid/F[N-tmp-1];
            if (cnt > K) {
                flag = false;
                break;
            }
        }
        if (flag) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}
