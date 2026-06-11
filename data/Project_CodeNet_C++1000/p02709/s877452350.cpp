#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;

template<typename T>
void print(const vector<T> &x) {
    int n = x.size();
    rep(i,n) {
        cout << x[i];
        if (i!=n-1) cout<<" ";
        else cout << endl;
    }
}

template<typename T>
void print(const vector<vector<T>> &x) {
    int n = x.size();
    rep(i,n) {
        rep(j,x[i].size()) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

template<typename T>
void print(const vector<T> &x, int n) {
    rep(i,n) {
        cout << x[i];
        if (i!=n-1) cout<<" ";
        else cout << endl;
    }
}

template<typename T>
void print(const vector<vector<T>> &x, int n, int m) {
    rep(i,n) {
        rep(j,m) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void input_init() {
    cin.tie(0); ios::sync_with_stdio(false);
}

constexpr int MAX = 2020;
ll dp[MAX][MAX];

int main(int argc, char const *argv[]) {
    int n; cin>>n;
    vector<P> a(n);
    rep(i,n) {
        cin>>a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end(), greater<>());
    rep(i,MAX) rep(j,MAX) dp[i][j] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; i+j < n; ++j) {
            int idx = i+j;
            ll lcost = a[idx].first * (a[idx].second-i);
            chmax(dp[i+1][j], dp[i][j]+lcost);
            ll rcost = a[idx].first * ((n-j-1) - a[idx].second);
            chmax(dp[i][j+1], dp[i][j]+rcost);
        }
    }

    ll ans = 0;
    rep(i,n+1) {
        chmax(ans, dp[i][n-i]);
    }
    cout << ans << '\n';
    return 0;
}