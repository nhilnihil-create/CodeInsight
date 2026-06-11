#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <prettyprint.hpp>
#define debug(...)  cerr << "[" << #__VA_ARGS__ << "]: ", d_err(__VA_ARGS__);
#else
#define debug(...) 83;
#endif

void d_err() {
    cerr << endl;
}

template <typename H, typename... T>
void d_err(H h, T... t) {
    cerr << h << " ";
    d_err(t...);
}

template <typename T>
void print(T x) {
    cout << x << "\n";
}

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REVFOR(i, m, n) for (int i = (n - 1); i >= (m); --i)
#define REP(i, n) FOR(i, 0, n)
#define REVREP(i, n) REVFOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define bcnt __builtin_popcountll

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> Pll;
typedef pair<int,int> Pin;

ll INF = 1e16;
int inf = 1e9;

void chmax(ll& x, ll y) {
    if (x < y) x = y;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);


    while(1){
        int n; cin >> n;

        if (n == 0) break;
        vector<int> s(250100, 0);

        REP(i, n) {
            string l, r; cin >> l >> r;

            int li = 0, ri = 0;
            REP(j, 8) {
                if (j == 2 || j == 5) continue;
                li *= 10;
                li += l[j] - '0';

                ri *= 10;
                ri += r[j] - '0';
            }

            s[li]++;
            s[ri]--;
        }

        FOR(i, 1, s.size()) s[i] += s[i - 1];

        print(*max_element(ALL(s)));
    }

}
