#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N;
vector<ll> A;

int main() {
    cin >> N;
    A.resize(N);
    rep(i, N) cin >> A[i];

    // 山1に流す量を求める
    vector<ll> ans(N);

    ll tmp = 0;
    rep(i, N) {
        // 奇数個目は足す
        if (i % 2 == 0) {
            tmp += A[i];
        } else {
        // 偶数個目は減らす
            tmp -= A[i];
        }
    }
    ans[0] = tmp;

    // A[i] - (1個前の流量 / 2) 
    for (int i = 0; i <= N - 2; i++) {
        ans[i + 1] = 2 * (A[i] - (ans[i] / 2));
    }


    rep(i, N) {
        cout << ans[i] << " ";
    }
    cout << endl;
}