#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n, ans = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < 1000; ++i) {
        int ieei[3] = {i / 100, i / 10 % 10, i % 10};
        int idx = 0;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] - '0' == ieei[idx])
                idx++;
            if (idx == 3) {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}