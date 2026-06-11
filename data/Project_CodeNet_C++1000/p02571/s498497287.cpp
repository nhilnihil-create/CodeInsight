#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int maxn = 2e5 + 5;
typedef long long ll;
typedef uint64_t HT;
const int mod = 1e9 + 7;
int main() {
    string s, t;
    cin >> s >> t;
    int lens = s.length();
    int lent = t.length();
    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= lens - lent; i++) {
        int cnt = 0;
        int pos = 0;
        while (pos < lent) {
            if (t[pos] != s[i + pos]) {
                cnt++;
            }
            pos++;
        }
        ans = min(ans, cnt);
    }
    cout << ans << "\n";
    return 0;
}