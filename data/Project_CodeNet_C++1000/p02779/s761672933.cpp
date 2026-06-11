#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.in" , "r" , stdin);
#endif
    int n;
    cin >> n;

    set<int> st;
    for (int i = 0 ;i < n ;i++) {
        int x;
        cin >> x;
        st.insert(x);
    }

    cout << (st.size() == n ? "YES" : "NO");
}