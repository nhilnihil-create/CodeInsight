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
    int N = S.size();

    bool isOk = true;
    rep(i, N / 2) {  // condition 1
        if (S.at(i) != S.at(N - 1 - i)) isOk = false;
    }

    int limit2 = (N - 1) / 2;
    for (int i = 0; i < limit2; i++) {  //condition 2
        if (S.at(i) != S.at(limit2 - 1 - i)) isOk = false;
    }

    int limit3 = (N + 3) / 2;
    int j = 0;
    for (int i = limit3 - 1; i < N; i++) {
        if (S.at(i) != S.at(N - 1 - j)) isOk = false;
        j++;
    }

    string ans = isOk ? "Yes" : "No";

    cout << ans << endl;

    return 0;
}
