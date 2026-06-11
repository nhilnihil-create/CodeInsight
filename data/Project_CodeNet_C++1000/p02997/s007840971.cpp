
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
#define REP(i, n) FOR(i, 0, n)
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

    int k = (N - 2) * (N - 1) / 2;

    if (K > k) {
        print(-1);
        return 0;
    }

    vector<pair<int, int>> ans;
    REP(i, N - 1) {
        ans.eb(1, i + 2);
    }

    int i = 2, j = 3;
    while(k > K && i < N + 1 && j < N + 1) {
        if (i == j) {
            if (j == N) {
                i++; j = i + 1;
            } else {
                j++;
            }
        }

        ans.eb(i, j);
        k--;

        if (j == N) {
            i++; j = i + 1;
        } else {
            j++;
        }
    }

    if (k != K) {
        print(-1);
        return 0;
    }

    print(ans.size());
    for(auto &e: ans) {
        cout << e.fi << " " << e.se << endl;
    }

}
