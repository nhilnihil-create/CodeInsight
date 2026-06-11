#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}

#ifndef DEBUG
void debug() { cerr << "\n"; }
template <class T> void debug(const T &x) { cerr << x << "\n"; }
template <class T, class... Args> void debug(const T &x, const Args &... args) {
    cerr << x << " ";
    debug(args...);
}
template <class T> void debugVector(const vector<T> &v) {
    for(const T &x : v) {
        cerr << x << " ";
    }
    cerr << "\n";
}
#else
template <class T, class... Args>
void debug(const T &x, const Args &... args) {}
template <class T> void debugVector(const vector<T> &v) {}
#endif

using ll = long long;
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
constexpr int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K, C;
    cin >> N >> K >> C;
    string s;
    cin >> s;
    vector<int> L, R;
    int lastd = -INF;
    for(int i = 0; i < N; i++) {
        if(s[i] == 'o' && lastd + C < i) {
            lastd = i;
            L.emplace_back(i);
        }
        if(L.size() == K) {
            break;
        }
    }
    lastd = INF;
    for(int i = N - 1; i >= 0; i--) {
        if(s[i] == 'o' && i + C < lastd) {
            lastd = i;
            R.emplace_back(i);
        }
        if(R.size() == K) {
            break;
        }
    }
    reverse(ALL(R));
    for(int i = 0; i < K; i++) {
        if(L[i] == R[i]) {
            cout << L[i] + 1 << "\n";
        }
    }
}