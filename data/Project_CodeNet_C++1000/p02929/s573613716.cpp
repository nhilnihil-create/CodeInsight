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
#define FOR(i,m,n) for (int i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define ALL(v) v.begin(), v.end()

const int MAX = 2e5+10;
const int MOD = 1e9+7;

int N;
vi S;
vi lt;

ll solve() {
    int flip = 0;
    REP (i, 2*N) {
        if ((flip + S[i]) % 2 == 0) {
            lt.PB(0);
            flip--;
        } else {
            lt.PB(1);
            flip++;
        }
        if (flip < 0) return 0;
    }
    if (flip != 0) return 0;

    ll res = 1;
    int cnt = 0;
    REP (i, 2*N) {
        if (lt[i]) {
            cnt++;
        } else {
            res *= cnt;
            res %= MOD;
            cnt--;
        }
    }

    FOR (i, 1, N+1) {
        res *= i;
        res %= MOD;
    }
    return res;
}

int main() {
    string s;
    cin >> N >> s;
    REP (i, 2*N) {
        S.PB(s[i] == 'B');
    }
    cout << solve() << endl;
}