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

const int MAX = 3e5+10;

int N, A[MAX];
ll s[MAX];

ll sub(int k) {
    ll ok = 0, ng = MAX;
    while (ng - ok > 1) {
        ll mid = (ng + ok) / 2;
        if (s[mid]/mid >= k) ok = mid;
        else ng = mid;
    }
    return ok;
}

vi solve() {
    map<ll, ll> m;
    REP (i, N) m[A[i]]++;
    vi cnt;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        cnt.push_back(iter->second);
    }
    sort(ALL(cnt));
    s[1] = cnt.size();
    FOR (i, 2, N+1) {
        s[i] = s[i-1] + (cnt.end() - lower_bound(ALL(cnt), i));
    }

    vi ans;
    FOR (i, 1, N+1) ans.push_back(sub(i));
    return ans;
}

int main() {
    cin >> N;
    REP (i, N) cin >> A[i];
    FORE (x, solve()) cout << x << endl;
}