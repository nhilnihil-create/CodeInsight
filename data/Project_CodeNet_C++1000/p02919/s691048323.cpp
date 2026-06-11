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
    int n; cin>>n;
    vector<int> p(n);
    vector<P> a(n);
    rep(i,n) {
        cin>>p[i];
        a[i].first = p[i];
        a[i].second = i;
    }

    multiset<int> st;
    st.insert(-1); st.insert(n);
    st.insert(-1); st.insert(n);
    sort(a.begin(), a.end(), greater<>());
    st.insert(a[0].second);

    ll ans = 0;

    for (int i = 1; i < n; ++i) {
        auto r1 = st.lower_bound(a[i].second);
        auto r2 = next(r1);
        auto l2 = prev(r1);
        auto l1 = prev(l2);
        ll c = a[i].second;
        ll x = a[i].first;
        ll tmp = (c-*l2)*(*r2-*r1) + (*r1-c)*(*l2-*l1);
        tmp *= x;
        ans += tmp;
        st.insert(c);
    }

    cout << ans << '\n';
    return 0;
}