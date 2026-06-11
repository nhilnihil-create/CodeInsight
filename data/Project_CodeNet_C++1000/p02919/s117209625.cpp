#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    vector<pair<ll,ll>> p(n);
    rep(i, 0, n) {
        cin >> p[i].first;
        p[i].second = i+1;
    }
    sort(p.begin(), p.end(), greater<pair<ll,ll>>());
    ll ans = 0;
    multiset<ll> st;
    st.insert(0);
    st.insert(0);
    st.insert(n+1);
    st.insert(n+1);
    rep(i, 0, n) {
        auto itr = st.lower_bound(p[i].second);
        ll r1 = *itr;
        itr++;
        ll r2 = *itr;
        itr = st.lower_bound(p[i].second);
        itr--;
        ll l1 = *itr;
        itr--;
        ll l2 = *itr;
        ans += (l1 - l2) * (r1 - p[i].second) * p[i].first;
        ans += (r2 - r1) * (p[i].second - l1) * p[i].first;

        st.insert(p[i].second);
    }
    cout << ans << endl;
    return 0;
}