#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr ll mod = 1e9 + 7;

template <typename T> inline bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> inline bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n = 18;
    cin >> n;
    vector<int> s(1 << n);
    rep(i, 1 << n) cin >> s[i];
    sort(ALL(s));
    multiset<int> st;
    rep(i, (1 << n) - 1) st.insert(s[i]);
    vector<int> v(1, s[(1 << n) - 1]);
    rep(i, n) {
        int siz = v.size();
        for(int j = siz - 1; j >= 0; j--) {
            auto itr = st.lower_bound(v[j]);
            if(itr == st.begin()) {
                cout << "No" << endl;
                return 0;
            }
            itr--;
            v.push_back(*itr);
            st.erase(itr);
        }
        sort(ALL(v));
    }
    cout << "Yes" << endl;
    return 0;
}