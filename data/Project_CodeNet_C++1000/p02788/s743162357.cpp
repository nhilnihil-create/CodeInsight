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
    int N, D, A; cin >> N >> D >> A;
    vector<pair<int, ll>> vec(N);
    rep(i, N) {
        ll X, H;
        cin >> X >> H;
        vec[i] = make_pair(X, H);
    }
    sort(ALL(vec));
    vector<int> vec_right(N);
    rep(i, N) {
        int ok = i, ng = N;
        while(abs(ok-ng) > 1) {
            int mid = (ok+ng)/2;
            if (vec[mid].first - vec[i].first <= 2*D) ok = mid;
            else ng = mid;
        }
        vec_right[i] = ng;
    }
    vector<ll> point_sum(N+1);
    ll ans = 0;
    rep(i, N) {
        if (point_sum[i] >= vec[i].second) {
            point_sum[i+1] += point_sum[i];
            continue;
        }
        ll tmp = (vec[i].second - point_sum[i])%A ? (vec[i].second - point_sum[i])/A + 1 : (vec[i].second - point_sum[i])/A;
        ans += tmp;
        point_sum[i] += tmp*A;
        point_sum[vec_right[i]] -=  tmp*A;
        point_sum[i+1] += point_sum[i];
    }
    cout << ans << endl;
}
