#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, K;
    cin >> N >> K;
    set<int> st;
    rep(i, K) {
        int D;
        cin >> D;
        rep(i, D) {
            int a;
            cin >> a;
            st.insert(a);
        }
    }
    int ans = N - sz(st);
    cout << ans << '\n';
    return 0;
}