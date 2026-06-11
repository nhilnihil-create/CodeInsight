#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int n, k, d, a;
    set<int> st;
    cin >> n >> k;
    rep(i, k) {
        cin >> d;
        rep(i, d) {
            cin >> a;
            st.insert(a);
        }
    }
    cout << n - st.size() << endl;
    return 0;
}