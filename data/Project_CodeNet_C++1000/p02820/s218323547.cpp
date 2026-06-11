
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
    cout << x << endl;
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
ll MOD = 1e9+7;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    int N, K;
    cin >> N >> K;

    int R, S, P;
    cin >> R >> S >> P;

    string T;
    cin >> T;

    vector<string> v(K);

    REP(i, T.size()) {
        v[i % K] += T[i];
    }

    map<char, ll> scores;
    scores['r'] = P;
    scores['s'] = R;
    scores['p'] = S;


    ll ans = 0;
    REP(i, v.size()) {
        bool state = false;

        if (v[i].empty()) continue;

        ans += scores[v[i][0]];
        FOR(j, 1, v[i].size()) {
            if (v[i][j] != v[i][j - 1]) {
                state = false;
                ans += scores[v[i][j]];
            } else {
                if (state) ans += scores[v[i][j]];
                state ^= true;
            }
        }
    }

    print(ans);

    
}
