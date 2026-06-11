#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(unique(all(x)), x.end());
typedef long long ll;
typedef complex<double> Complex;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    rep(i, n) {
        int p;
        cin >> p;
        v[i] = make_pair(p, i);
    }
    sort(all(v));
    reverse(all(v));
    vector<int> p(n);
    rep(i, n) {
        p[i] = v[i].second;
    }
    // rep(i, n) cout << p[i] << " ";
    // cout << endl;
    set<int> st;
    st.insert(-2);
    st.insert(-1);
    st.insert(n);
    st.insert(n + 1);

    ll ans = 0;
    rep(i, n) {
        int num = n - i;
        auto itr = st.lower_bound(p[i]);
        itr++;
        int rightsright = *itr;
        itr--;
        int right = *itr;
        itr--;
        int left = *itr;
        itr--;
        int leftsleft = *itr;

        ll now = 0;
        if (left != -1) {
            now += (ll)(left - leftsleft) * (right - p[i]);
        }
        if (right != n) {
            now += (ll)(rightsright - right) * (p[i] - left);
        }
        now *= (ll)num;
        ans += now;
        st.insert(p[i]);
        // for (int x : st) cout << x << " ";
        // cout << endl;
        // cout << left << " " << right << endl;
        // cout << ans << endl;
    }
    cout << ans << endl;
}
