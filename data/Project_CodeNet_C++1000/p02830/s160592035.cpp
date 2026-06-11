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
    string S, T;
    cin >> S >> T;

    string ans;
    rep(i, N) {
        ans += S.at(i);
        ans += T.at(i);
    }

    cout << ans << endl;
    
    return 0;
}
