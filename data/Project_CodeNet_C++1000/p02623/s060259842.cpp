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

int main(int argc, char const *argv[]) {
    ll n,m,k; cin>>n>>m>>k;
    vector<ll> a(n),b(m), sa(n+1), sb(m+1);
    rep(i,n) cin>>a[i];
    rep(i,m) cin>>b[i];
    rep(i,n) sa[i+1] = sa[i]+a[i];
    rep(i,m) sb[i+1] = sb[i]+b[i];

    ll ans = 0;
    rep(i,n+1) {
        ll tmp = i;
        ll x = k-sa[i];
        if (x <= 0) continue;
        auto itr = upper_bound(sb.begin(), sb.end(), x);
        tmp += (itr-(sb.begin()+1));
        chmax(ans, tmp);
    }

    rep(i,m+1) {
        ll tmp = i;
        ll x = k-sb[i];
        if (x<=0) continue;
        auto itr = upper_bound(sa.begin(), sa.end(), x);
        tmp += (itr-(sa.begin()+1));
        chmax(ans,tmp);
    }

    cout << ans << '\n';
    return 0;
}