#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout << (x) << '\n'
#define Int int64_t
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
 
Int INF = 1e18;
int inf = 1e9;
Int mod = 1e9+7;

int main() {
    Int n;
    cin >> n;
    vector<Int> a(n);
    for (Int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<Int, Int> mp;
    for (Int i = 0; i < n; i++) {
        mp[a[i]] = i + 1;
    }
    sort(rall(a));
    multiset<Int> st;
    st.insert(0);
    st.insert(0);
    st.insert(n + 1);
    st.insert(n + 1);
    st.insert(mp[a[0]]);
    Int res = 0;
    for (Int i = 1; i < n; i++) {
        Int index = mp[a[i]];
        auto itr = st.lower_bound(index);
        Int R1 = *itr; itr++;
        Int R2 = *itr; itr--; itr--;
        Int L1 = *itr; itr--;
        Int L2 = *itr;
        //dump(index);
        //cout << L2 << " " << L1 << " " << R1 << " " << R2 << endl;
        Int cnt = (R2 - R1) * (index - L1) + (L1 - L2) * (R1 - index);
        res += a[i] * cnt;
        st.insert(index);
    }
    dump(res);
    return 0;
}