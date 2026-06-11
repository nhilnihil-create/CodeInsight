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

ll calc1(const string &s, int n) {
    ll ret = 0;
    for (int i = 0; i < n-2; ++i) {
        for (int j = i+1; j < n-1; ++j) {
            for (int k = j+1; k < n; ++k) {
                if (j-i == k-j) continue;
                if (s[i] != s[j] && s[j] != s[k] && s[i] != s[k]) ret++;
            }
        }
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    int n; cin>>n;
    string s; cin>>s;
    vector<ll> r(n+10), g(n+10), b(n+10);
    rep(i,n) {
        if (s[i] == 'R') {
            r[i+1] = r[i]+1;
            g[i+1] = g[i];
            b[i+1] = b[i];
        }
        else if (s[i] == 'G') {
            g[i+1] = g[i]+1;
            r[i+1] = r[i];
            b[i+1] = b[i];
        }
        else {
            b[i+1] = b[i]+1;
            r[i+1] = r[i];
            g[i+1] = g[i];
        }
    }

    ll ans = 0;
    for (int j = 1; j < n-1; ++j) {
        for (int k = n-1; k > j; --k) {
            set<char> st;
            st.insert(s[j]); st.insert(s[k]);
            if (st.size() == 1) continue;
            int d = k-j;
            d = j-d;
            if (!st.count('R')) {
                ans += r[j];
                if (d >= 0 && s[d] == 'R') ans--;
            }
            else if (!st.count('G')) {
                ans += g[j];
                if (d >= 0 && s[d] == 'G') ans--;
            }
            else if (!st.count('B')) {
                ans += b[j];
                if (d >= 0 && s[d] == 'B') ans--;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}