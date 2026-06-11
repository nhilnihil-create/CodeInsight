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
    string S;
    cin >> S;

    bool isOk = true;
    if (N % 2 == 1) isOk = false;
    if (S.substr(0, N / 2) != S.substr(N / 2, N / 2)) isOk = false;

    string ans = isOk ? "Yes" : "No";

    cout << ans << endl;

    return 0;
}
