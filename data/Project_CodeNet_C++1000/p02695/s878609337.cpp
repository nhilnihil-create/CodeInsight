#include <bits/stdc++.h>
#include <algorithm>
#include <functional>
#include <stack>
#include <set>
#include <queue>
#include <map>
using namespace std;
#define rep(i, m, n) for (int(i) = (int)(m); i < (int)(n); ++i)
#define rep2(i, m, n) for (int(i) = (int)(n)-1; i >= (int)(m); --i)
#define REP(i, n) rep(i, 0, n)
#define REP2(i, n) rep2(i, 0, n)
#define all(hoge) (hoge).begin(), (hoge).end()
#define en '\n'
using ll = long long;
using ull = unsigned long long;
typedef vector<ll> vec;
typedef vector<vector<ll>> mat;
typedef vector<vector<vector<ll>>> mat3;
typedef vector<string> svec;
typedef vector<vector<string>> smat;
typedef pair<ll, ll> P;
constexpr long long INF = 1LL << 60;
constexpr int INF_INT = 1 << 25;
constexpr long long MOD = (ll)1e9 + 7;
// constexpr long long MOD = 998244353LL;
using ld = long double;
static const ld pi = 3.141592653589793L;
template <class T> bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
// ~~~~~~~~~~~~~~memo~~~~~~~~~~~~~~
// for (int i = 0; i < n; ++i)
// vector<long long> v(n), c(n);
// cout << res << endl;
// cout << res << '\n';
// int型の2次元配列(h×w要素の)の宣言
// vector<vector<int>> data(h, vector<int>(w));
// rotate(s.begin(), s.begin() + 1, s.end());
// sort(all(a),greater<int>());
// s.substr(0,2) 先頭から2文字切り出す
// for (auto it = mp.rbegin();it != mp.rend(); ++it)
int N,M,Q;
vector<ll> a,b,c,d;

ll calc(vector<int> &L) {
    ll res = 0;
    rep(i,0,Q) if (L[b[i]]-L[a[i]] == c[i]) res += d[i];
    return res;
}

ll dfs(vector<int> &L) {
    if (L.size() == N) {
        return calc(L);
    }
    ll res = 0;
    int prev_last = 0;
    if (L.empty()) {
        prev_last = 0;
    } else {
        prev_last = L.back();
    }
    for (int i = prev_last;i < M; ++i) {
        L.push_back(i);
        res = max(res,dfs(L));
        L.pop_back();
    }
    return res;
}



int main() {
    cin >> N >> M >> Q;
    a.resize(Q);b.resize(Q);c.resize(Q);d.resize(Q);
    rep(i,0,Q) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        --a[i];--b[i];
    }
    vector<int> L;
    cout << dfs(L) << '\n';
    return 0;
}
