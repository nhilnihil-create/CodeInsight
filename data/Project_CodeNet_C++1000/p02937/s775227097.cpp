#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    int N = S.size(), M = T.size();
    S += S;
    map<char, vector<int>> mp;
    for(int i = 0; i < 2 * N; ++i) mp[S[i]].push_back(i);
    int64_t ans = -1;
    for(auto &c : T) {
        int i = ans % N;
        auto it = upper_bound(mp[c].begin(), mp[c].end(), i);
        if(it == mp[c].end()) {
            cout << -1 << '\n';
            return 0;
        }
        ans += *it - i;
    }
    cout << ans + 1 << '\n';
    return 0;
}
