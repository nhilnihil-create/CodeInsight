#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1 << 29;
const int MOD = 1000000007;

int main() {
    long long n;
    cin >> n;
    string ans = "";
    /*
    while (n > 0) {
        // nを26で割ったあまりを求める
        int res = n % 26;
        // あまりが0なら26に変える(zに相当)
        if (res == 0) {
            res = 26;
        }
        // 余りは文字を付け足す
        ans += (char)('a' + res - 1);
        // 余りを引いて26で割る(小数点切り捨て)
        n = (n - res) / 26;
    }
    */
    while (n) {
        n--;
        ans += (char)('a' + (n % 26));
        n /= 26;
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}
