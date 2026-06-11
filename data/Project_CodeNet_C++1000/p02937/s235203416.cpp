#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    int N = S.size();
    map<char, vector<int>> mp;
    for(int i = 0; i < 2 * N; ++i) mp[S[i % N]].push_back(i);
    int64_t now = -1;
    for(auto &c : T) {
        int i = now % N;
        auto it = upper_bound(mp[c].begin(), mp[c].end(), i);
        if(it == mp[c].end()) {
            cout << -1 << '\n';
            return 0;
        }
        now += *it - i;
    }
    cout << now + 1 << '\n';
    return 0;
}
