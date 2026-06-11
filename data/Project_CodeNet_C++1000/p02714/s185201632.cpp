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
    string s; cin>>s;
    vector<int> r(n), g(n), b(n);
    rep(i,n) {
        if (s[i] == 'R') r[i]++;
        else if (s[i] == 'G') g[i]++;
        else b[i]++;
    }

    rep(i,n-1) {
        r[i+1] += r[i];
        g[i+1] += g[i];
        b[i+1] += b[i];
    }

    ll ans = 0;
    rep(i,n-2) {
        for (int j = i+1; j < n-1; ++j) {
            if (s[i] == s[j]) continue;
            set<char> st;
            st.insert(s[i]); st.insert(s[j]);
            if (!st.count('R')) {
                ans += (r.back()-r[j]);
                int k = j+(j-i);
                if (k < n && s[k]=='R') ans--;
            }
            else if (!st.count('G')) {
                ans += (g.back()-g[j]);
                int k = j+(j-i);
                if (k < n && s[k]=='G') ans--;
            }
            else if (!st.count('B')) {
                ans += (b.back()-b[j]);
                int k = j+(j-i);
                if (k < n && s[k]=='B') ans--;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}