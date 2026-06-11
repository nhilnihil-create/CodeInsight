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

const int MAX = 505;

int N;

void solve() {
    FOR (a, 1, N+1) FOR (b, a+1, N+1) {
        int c = (a^b);
        int k = 1;
        while(c%2 == 0) {
            k++;
            c >>= 1;
        }
        cout << k << ((b == N) ? "\n" : " ");
    }
}

int main() {
    cin >> N;
    solve();
}