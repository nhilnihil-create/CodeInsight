#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    // 左右それぞれの自分より大きいもの2つ
    // 大きいものから順にsetに入れていく
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    rep(i, N) A[i]--;
    vector<int> idx(N);
    rep(i, N) idx[A[i]] = i;
    ll ans = 0;
    set<int> st;
    for (int x = N-1; x >= 0; x--) {
        int i = idx[x];
        st.insert(i);
        vector<int> lpos(2, -1);
        vector<int> rpos(2, N);
        {
            auto it = st.find(i);
            rep(j, 2) {
                if (it == st.begin()) break;
                it--;
                lpos[j] = *it;
            }
        }
        {
            auto it = st.find(i);
            rep(j, 2) {
                it++;
                if (it == st.end()) break;
                rpos[j] = *it;
            }
        }
        vector<int> Llen(2);
        vector<int> Rlen(2);
        Llen[0] = i - lpos[0]; Llen[1] = lpos[0] - lpos[1];
        Rlen[0] = rpos[0] - i; Rlen[1] = rpos[1] - rpos[0];
        ll coef = (ll)Llen[0] * Rlen[1] + (ll)Llen[1] * Rlen[0];
        ans += coef * (x+1);
    }
    cout << ans << '\n';
    return 0;
    // ll, 0, -, 1i, for s&g, debug
}