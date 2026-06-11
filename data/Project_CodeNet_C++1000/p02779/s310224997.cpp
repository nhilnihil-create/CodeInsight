#include <bits/stdc++.h>
//#include <ext/numeric>


using namespace std;
//using namespace __gnu_cxx;

//const int MAXN = (int)1e5 + 5;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(10), cout << fixed;

    int n;
    cin >> n;
    set<int> st;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        st.insert(x);
    }

    if (st.size() == n) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}