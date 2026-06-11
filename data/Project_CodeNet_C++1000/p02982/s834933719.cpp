#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int N, D;
    cin >> N >> D;
    vector<vector<int>> x(N, vector<int>(D));
    rep(i, N) {
        rep(j, D) {
            cin >> x.at(i).at(j);
        }
    }

    int ans = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {  // 2点選択
            double sum = 0;
            for (int k = 0; k < D; k++) {  // 点の距離を計算
                sum += pow(x.at(i).at(k) - x.at(j).at(k), 2);
            }
            for (int l = 1; l <= sum; l++) {
                if (sum == l * l) ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
