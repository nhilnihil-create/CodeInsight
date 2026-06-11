#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i, s, n) for (int i = s; i < (n); i++)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using ll = long long;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
const ll INF = MOD * MOD;
const int inf = (1<<29);

int n, m, q;
vector<int> a, b, c, d;

ll score (const vector<int> &A) {
    ll res = 0;
    for(int i = 0; i < q; i++) {
        if (A[b[i]] - A[a[i]] == c[i]) res += d[i];
    }
    return res;
}

ll dfs(vector<int> &A) {
    if (A.size() == n) {
        return score(A);
    }

    ll res = 0;
    int prev_last = (A.empty() ? 1 : A.back());
    for (int v = prev_last; v <= m; v++) {
        A.push_back(v);
        res = max(res, dfs(A));
        A.pop_back();
    }

    return res;
    
}

int main() {

    cin >> n >> m >> q;
    a.resize(q); b.resize(q); c.resize(q); d.resize(q);    
    REP(i, q) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--; b[i]--;
    }

    vector<int> A;
    cout << dfs(A) << endl;

    return 0;
}