#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> p(n), idx(n);
    rep(i, n) {
        cin >> p[i];
        p[i]--;
        idx[p[i]] = i;
    }
    set<int> st;
    ll ans = 0;
    for (int i = n-1; i >= 0; --i) {
        int id = idx[i];
        st.insert(id);
        int l1, l2, r1, r2;
        l1 = l2 = -1;
        r1 = r2 = n;
        auto it_l = st.find(id);
        auto it_r = st.find(id);
        if (it_l != st.begin()) {
            it_l--;
            l1 = *it_l;
            if (it_l != st.begin()) {
                it_l--;
                l2 = *it_l;
            }
        }
        it_r++;
        if (it_r != st.end()) {
            r1 = *it_r;
            it_r++;
            if (it_r != st.end()) {
                r2 = *it_r;
            }
        }
        if (ll(id-l1) * (r2-r1) + ll(l1-l2) * (r1-id) < 0) {
            cout << id << endl;
            cout << l1 << endl;
            cout << l2 << endl;
            cout << r1 << endl;
            cout << r2 << endl;
            cout << "OK" << endl;
        }
        ans += (ll(id-l1) * (r2-r1) + ll(l1-l2) * (r1-id)) * (i+1);
    }
    cout << ans << endl;
    return 0;
}