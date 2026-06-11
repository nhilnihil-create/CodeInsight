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
    string S;
    cin >> N >> S;

    int ans = 0;
    rep(i, N - 2) {
        if ('A' == S.at(i) && 'B' == S.at(i + 1) && 'C' == S.at(i + 2)) ans++;
    }

    cout << ans << endl;

    return 0;
}
