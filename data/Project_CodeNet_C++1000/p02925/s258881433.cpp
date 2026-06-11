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
    int n; cin>>n;
    int m = n*(n-1)/2;
    vector<vector<int>> g(n*(n-1)/2);
    vector<int> h(m);
    map<P,int> node;
    int cnt = 0;
    rep(i,n) {
        vector<int> to(n-1);
        rep(j,n-1) {
            cin>>to[j];
            --to[j];
        }
        rep(j,n-2) {
            int u,v;
            int a = i; int b = to[j];
            if (a>b) swap(a,b);
            if (!node.count(P(a,b))) {
                u = cnt;
                node[P(a,b)] = cnt;
                cnt++;
            }
            else  {
                u = node[P(a,b)];
            }
            // cout << a+1 << "-" << b+1 << " -> ";
            a = i; b = to[j+1];
            if (a>b) swap(a,b);
            if (!node.count(P(a,b))) {
                node[P(a,b)] = cnt;
                v = cnt;
                cnt++;
            }
            else {
                v = node[P(a,b)];
            }
            g[u].push_back(v);
            // cout << a+1 << "-" << b+1 << '\n';
            // cout << u << " -> " << v << '\n';
            h[v]++;
        }
    }

    

    stack<int> st;
    vector<int> topo;
    rep(i,m) if (h[i]==0) {
        st.push(i);
    }

    while (st.size()) {
        int v = st.top(); st.pop();
        topo.push_back(v);
        for (auto&& e: g[v]) {
            h[e]--;
            if (h[e]==0) st.push(e);
        }
    }
    if (topo.size() != m) {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> dp(m);
    int ans = 0;
    for (auto &&e: topo) {
        for (auto &&f: g[e]) {
            chmax(dp[f], dp[e]+1);
        }
    }

    rep(i,m) chmax(ans,dp[i]);

    cout << ans+1 << '\n';
    return 0;
}