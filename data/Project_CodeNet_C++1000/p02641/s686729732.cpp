#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int X, N;
    cin >> X >> N;
    set<int> st;
    rep(i, N) {
        int p;
        cin >> p;
        st.insert(p);
    }
    int ans = 0;
    for (int i = 1; i <= 101; i++) {
        if (st.count(i)) continue;
        if (abs(i - X) < abs(ans - X)) ans = i;
    }
    cout << ans << '\n';
    return 0;
}