#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    rep(i, N) cin >> A.at(i);

    sort(A.begin(), A.end(), greater<int>());

    int sumOfVotes = 0;
    rep(i, N) {
        sumOfVotes += A.at(i);
    }

    double minOfVotes = (double)sumOfVotes / (4 * M);

    string ans = "Yes";
    rep(i, M) {
        if (A.at(i) < minOfVotes) ans = "No";
    }

    cout << ans << endl;

    return 0;
}
