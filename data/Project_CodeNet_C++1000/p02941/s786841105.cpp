#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define REPR(i,n) for (ll i = n-1; i >= 0; --i)
#define FOR(i,m,n) for (ll i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define ALL(v) v.begin(), v.end()
#define CHMIN(x,y) x = min(x, y)
#define CHMAX(x,y) x = max(x, y)

const int MAX = 2e5+10;
const int NG = -1;

int N;
ll A[MAX], B[MAX];

ll solve() {
    priority_queue<ii> q;
    ll ans = 0;
    REP (i, N) {
        if (B[i] == A[i]) continue;
        if (B[i] < A[i]) return NG;
        q.push(ii(B[i], i));
    }

    while (!q.empty()) {
        ll i = q.top().second;
        q.pop();
        ll r = B[(i+1)%N] + B[(N+i-1)%N];
        ll k = (B[i] - A[i]) / r;
        if (k <= 0) return NG;
        ans += k;
        B[i] -= r * k;
        if (A[i] == B[i]) continue;
        q.push(ii(B[i], i));
    }

    return ans;
}

int main() {
    cin >> N;
    REP (i, N) cin >> A[i];
    REP (i, N) cin >> B[i];
    cout << solve() << endl;
}