#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,n) for(ll i=0;i<(n);++i)
#define REPR(i,n) for(ll i=n;i>=0;i--)
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

int main(int argc, char const *argv[]) {
    ll n,k; cin>>n>>k;
    vector<ll> a(n);
    ll s = 0;
    rep(i,n) {
        cin>>a[i];
        s += a[i];
    }

    vector<ll> x;
    for (int i = 1; i*i <= s; ++i) {
        if (s%i == 0) {
            x.push_back(i);
            if (s/i != i) x.push_back(s/i);
        }
    }

    auto check = [&](ll t) -> bool {
        vector<ll> b(a);
        rep(i,n) b[i] = b[i]%t;
        sort(b.begin(), b.end());
        vector<ll> p(n+1),q(n+1);
        rep(i,n) p[i+1] = p[i]+b[i];
        for (int i = n-1; i >= 0; --i) q[i] = q[i+1]+(t-b[i]);
        ll cnt = LINF;
        for (int i = 0; i <= n; ++i) if (p[i]==q[i]) {
            chmin(cnt, p[i]);
        }
        if (k >= cnt) return true;
        else return false;
    };

    ll ans = 0;
    for (auto &&e: x) {
        if (check(e)) chmax(ans, e);
    }

    cout << ans << '\n';
    return 0;
}