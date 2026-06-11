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
    vector<P> a(n), b(n);
    rep(i,n) {
        cin>>a[i].first>>a[i].second;
        b[i].first = a[i].first;
        b[i].second = a[i].second;
    }
    
    sort(a.begin(), a.end(), [](const P &x, const P &y) {
        return x.first+x.second > y.first+y.second;
    });

    sort(b.begin(), b.end(), [](const P &x, const P &y) {
        return x.first-x.second > y.first-y.second;
    });

    ll max_a = a[0].first+a[0].second;
    ll min_a = a.back().first+a.back().second;
    ll max_b = b[0].first-b[0].second;
    ll min_b = b.back().first-b.back().second;
    ll A = abs(max_a-min_a);
    ll B = abs(max_b-min_b);
    cout << max(A,B) << '\n';

    return 0;
}