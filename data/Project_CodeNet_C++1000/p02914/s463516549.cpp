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

const int MAX = 1e5+10;
const int MAXBIT = 62;
int N;
ll A[MAX];

ll solve() {
    ll allxor = 0;
    REP (i, N) allxor ^= A[i];
    REP (i, N) A[i] &= ~allxor;
    int rank = 0;
    REPR (i, MAXBIT) {
        int j = rank;
        while (j < N) {
            if (A[j] & (1ll<<i)) break;
            j++;
        }
        if (j == N) continue;
        swap(A[rank], A[j]);
        FOR (j, rank+1, N) {
            if (A[j] & (1ll<<i)) A[j] ^= A[rank];
        }
        rank++;
    }

    ll res = 0;
    REP (i, N) res = max(res, res^A[i]);
    return allxor + 2 * res;
}

int main() {
    cin >> N;
    REP (i, N) cin >> A[i];
    cout << solve() << endl;
}