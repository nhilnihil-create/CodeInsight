#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    string S;
    cin >> S;

    bool isOddOk = true;
    bool isEvenOk = true;
    rep(i, S.size()) {
        if(i % 2 == 1) { // even 
            if(S.at(i) == 'R') {
                isOddOk = false;
            }
        } else { // odd
            if(S.at(i) == 'L') {
                isEvenOk = false;
            }
        }
    }

    string ans = (isOddOk && isEvenOk) ? "Yes" : "No";

    cout << ans << endl;

    return 0;
}
