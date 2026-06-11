#include "bits/stdc++.h"

using namespace std;
using ll = long long;
#define endl '\n'
#define all(v) v.begin(), v.end()

int main() {
    string s, t;
    cin >> s >> t;
    int ls = s.size(), lt = t.size();
    int ans = t.size() + 1;
    for (int i = 0; i <= ls - lt;i++) {
        int op = 0;
        for (int j = 0; j < lt; j++) {
            if (t[j] != s[i+j])
                op++;
        }
        ans = min(ans, op);
    }
    cout << ans << '\n';
}
