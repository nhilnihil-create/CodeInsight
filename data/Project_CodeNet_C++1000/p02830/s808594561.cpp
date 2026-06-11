// 5/28
// 過去問ガリガリ
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
    int N;
    string S, T;
    cin >> N >> S >> T;

    string ans;
    rep(i, N) {
        ans += S[i];
        ans += T[i];
    }

    cout << ans << endl;
}
