#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    ll N, D, A;
    cin >> N >> D >> A;
    vector<pll> v(N);
    vector<ll> X(N + 1);
    vector<ll> H(N + 1);
    ll x, h;
    for (int i = 0; i < N; i++) {
        cin >> x >> h;
        v[i] = pll(x, h);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++) {
        X[i] = v[i].first;
        H[i] = v[i].second;
    }
    vector<pll>().swap(v);

    X[N] = LINF;
    H[N] = 0;
    vector<ll> sum(N + 1);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        H[i] += sum[i];
        if (H[i] <= 0) {
            sum[i+1] += sum[i];
            continue;
        }
        int cnt = ceil((double) H[i] / A);
        ans += cnt;
        sum[i] += -A * cnt;
        int ind = lower_bound(X.begin(), X.end(), X[i] + 2*D + 1) - X.begin();
        sum[ind] += A * cnt;
        sum[i+1] += sum[i];
    }
    cout << ans << '\n';
}
