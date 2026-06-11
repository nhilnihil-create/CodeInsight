#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 10;

int main() {
    int n;
    cin >> n;
    typedef pair<int, int> pa;
    vector<pa> v;
    for(int i = 1, x; i <= n; i++) {
        cin >> x;
        v.push_back(pa(x, i));
    }
    sort(v.begin(), v.end());
    multiset<int> st;
    st.insert(0);
    st.insert(0);
    st.insert(n+1);
    st.insert(n+1);
    ll ans = 0;
    for(int i = n-1; i >= 0; i--) {
        auto it = st.lower_bound(v[i].second);
        auto nxt = next(it), pre0 = prev(it);
        auto pre1 = prev(pre0);
        ans += 1LL*(*pre0 - *pre1)*(*it - v[i].second)*v[i].first;
        ans += 1LL*(*nxt - *it)*(v[i].second-*pre0)*v[i].first;
        st.insert(v[i].second);
    }
    cout << ans << '\n';
    return 0;
}