#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;
// ------------------------------

int main() {
    string S;
    cin >> S;
    vector<string> vec;
    int idx = 0;
    bool over = false;
    int ans = 0;
    rep(i, S.size()) {
        if (i == 0) {
            vec.push_back(string() + S[i]);
            ans += 1;
            continue;
        }
        string now = string() + S[i];
        while (vec[idx] == now) {
            if (i == S.size() - 1) {
                over = true;
                break;
            }
            i += 1;
            now = now + S[i];
        }
        if (over) break;
        vec.push_back(now);
        idx += 1;
        ans += 1;
    }
    cout << ans << endl;
    return 0;
}