#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int N;
    cin >> N;

    bool isOk = false;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if(i * j == N) {
                isOk = true;
            }
        }
    }

    string ans = isOk ? "Yes" : "No";

    cout << ans << endl;

    return 0;
}
