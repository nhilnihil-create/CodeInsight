#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N + 1);
    rep(i, N + 1) cin >> A[i];
    ll num = 1;
    vector<ll> lim(N + 1);
    rep(i, N + 1) {
        lim[i] = num;
        num -= A[i];
        if(i != N && num <= 0) {
            cout << -1 << endl;
            return 0;
        }
        num = min(num * 2, LINF);
    }

    ll cnt = 0;
    ll ans = 0;
    for(int i = N; i >= 0; i--) {
        if(cnt > (lim[i] - A[i]) * 2) {
            cout << -1 << endl;
            return 0;
        }
        if(cnt > lim[i] - A[i]) {
            cnt = lim[i] - A[i];
        }
        cnt += A[i];
        ans += cnt;
    }

    cout << ans << endl;
    return 0;
}