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
    vector<int> A(N);
    rep(i, N) cin >> A.at(i);

    string ans = "APPROVED";
    rep(i, N) {
        if(A.at(i) % 2 == 0 && A.at(i) % 3 !=  0 && A.at(i) % 5 != 0) {
            ans = "DENIED";
        }
    }

    cout << ans << endl;

    return 0;
}
