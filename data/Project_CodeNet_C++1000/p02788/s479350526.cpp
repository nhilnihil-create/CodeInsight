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
    ll x, h;
    for (int i = 0; i < N; i++) {
        cin >> x >> h;
        v[i] = pll(x, h);
    }
    v.push_back(pll(LINF, 0LL));
    sort(v.begin(), v.end());

    vector<ll> sum(N+1);
    ll times = 0;
    for (int i = 0; i < N; i++) {
        x = v[i].first, h = v[i].second;
        h -= sum[i];
        if (h <= 0LL) {
            sum[i+1] += sum[i];
            continue;
        }
        ll mul = (h + A - 1) / A;
        times += mul;
        ll bom = A * mul;
        sum[i] += bom;
        int ind = lower_bound(v.begin(), v.end(),
                    pll(x + 2*D + 1, 0)) - v.begin();
        sum[ind] -= bom;
        sum[i+1] += sum[i];
    }

    cout << times << '\n';
}
