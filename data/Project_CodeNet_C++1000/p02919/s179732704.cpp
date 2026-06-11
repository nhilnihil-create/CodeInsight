#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
pair<int,int> p[100010];
set<int> st;
ll ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].first;
        p[i].second = i;
    }
    
    sort(p,p+n);
    reverse(p,p+n);
    st.insert(-1);
    st.insert(n);

    for (int i = 0; i < n; i++) {
        st.insert(p[i].second);
        auto now = st.find(p[i].second);
        auto left = now;
        left--;
        auto right = now;
        right++;

        ll here = *now;
        ll l1 = *left;
        ll r0 = *right;

        ll l0,r1;

        if (l1 != -1) {
            left--;
            l0 = *left;
            
            ans += p[i].first * (l1 - l0) * (r0 - here);
        }
        if (r0 != n) {
            right++;
            r1 = *right;

            ans += p[i].first * (here - l1) * (r1 - r0);
        }
    }

    cout << ans << endl;
    return 0;
}
