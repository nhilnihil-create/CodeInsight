#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    string ans;
    while (A > 0 && C > 0) {
        C = C - B;
        if (C <= 0) {
            ans = "Yes";
            break;
        }
        A = A - D;
        if (A <= 0) {
            ans = "No";
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
