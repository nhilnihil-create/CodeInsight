// 6/22 解き直し
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int N, K;  // 勝負回数、K回前と同じ手は出せない
    int R, S, P;  // グー、チョキ、パーの勝ち点
    cin >> N >> K >> R >> S >> P;
    string t;  // グーチョキパー：r, s, p
    cin >> t;

    vector<bool> victory(N, false);

    int ans = 0;

    for (int i = N-1; i >= 0; i--) {
        // nextから決めていく。
        int next = i + K;
        if (next < N) {
            // nextと同じで、かつnextで勝っていたら勝てない。
            if (t[i] == t[next] && victory[next]) {
                // printf("%d回目：勝てない\n", i);
                continue;
            }
        }

        // 勝てる。
        if (t[i] == 'r') ans += P;
        else if (t[i] == 's') ans += R;
        else ans += S;
        victory[i] = true;
        // printf("%d回目：勝てる\n", i);
    }

    cout << ans << endl;
}