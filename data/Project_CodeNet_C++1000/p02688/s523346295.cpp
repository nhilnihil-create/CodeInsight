#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> d(K);
    vector<vector<int>> A(K);
    rep(i, K) {
        cin >> d.at(i);
        rep(j, d.at(i)) {
            int tmp;
            cin >> tmp;
            A.at(i).push_back(tmp);
        }
    }

    set<int> S;
    rep(i, K) {
        rep(j, d.at(i)) {
            S.insert(A.at(i).at(j));
        }
    }

    int ans = N - S.size();

    cout << ans << endl;

    return 0;
}
