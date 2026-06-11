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
    vector<P> p(n);
    rep(i,n) {
        cin>>p[i].first;
        p[i].second = i;
    }
    sort(p.begin(), p.end(), greater<>());
    multiset<ll> st; 
    st.insert(-1); st.insert(-1); st.insert(n); st.insert(n);
    ll ans = 0;
    rep(i,n) {
        int idx = p[i].second; ll v = p[i].first;
        st.insert(idx);
        auto itr = st.lower_bound(idx);
        auto l2 = prev(itr);
        auto l1 = prev(l2);
        auto r1 = next(itr);
        auto r2 = next(r1);

        // cout << "itr - l2 = " << *itr-*l2 << ", r2 - r1 = " << *r2-*r1 << '\n';
        // cout << "l2 - l1 = " << *l2-*l1 << ", r1 - itr = " << *r1-*itr << '\n';
        ans += ((*itr-*l2)*(*r2-*r1)*v);
        ans += ((*l2-*l1)*(*r1-*itr)*v);
        // cout << "ans = " << ans << '\n';
    }

    cout << ans << '\n';
    return 0;
}