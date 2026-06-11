#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N;
vector<ll> a;
int main() {
    cin >> N;
    a.resize(N + 1);
    rep(i, N) cin >> a[i + 1];

    // 後ろから決めてく
    vector<ll> ans(N + 1, -1);
    // reverse(a.begin(), a.end());

    // 倍数
    for (int i = N; i > 0; i--) {
        //  cout << i << endl;
        int loop_cnt = N / i;
        if (loop_cnt >= 2) {
            // cout << i << " over" << endl;
            // iより上は計算されている
            ll tmp = 0;
            for (int j = i + i; j <= N; j += i) {
                tmp += ans[j];
            }
            tmp = tmp % 2;
            ans[i] = tmp ^ a[i];
            // cout << tmp << endl;
        } else {
            // cout << i << " " << a[i] << endl;
            // 値固定するしかない
            ans[i] = a[i];
        }
    }

    // reverse(ans.begin(), ans.end());

    set<ll> st;
    for (int i = 1; i <= N; i++) {
        if (ans[i] == 1) {
            st.insert(i);
        };
    }

    cout << st.size() << endl;

    for (auto v : st) {
        cout << v << " ";
    }
    cout << endl;

    // for (int i = 0; i <= ans.size() - 1; i++) {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;
}