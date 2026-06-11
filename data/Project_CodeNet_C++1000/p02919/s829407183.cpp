#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> P(N), pos(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        pos[P[i]] = i + 1;
    }

    multiset<ll> st;
    ll ans = 0;
    st.insert(0);
    st.insert(0);
    st.insert(N + 1);
    st.insert(N + 1);
    for (ll i = N; i >= 1; i--) {
        auto itr = st.lower_bound(pos[i]);
        ll xr = *itr;
        itr++;
        ll xrr = *itr;
        itr--;
        itr--;
        ll xl = *itr;
        itr--;
        ll xll = *itr;

        ans += i * (xr - pos[i]) * (xl - xll);
        ans += i * (xrr - xr) * (pos[i] - xl);

        st.insert(pos[i]);
    }
    cout << ans << endl;
}
