#include <iostream>
using namespace std;

int main() {
    int D; cin >> D;
    int c[27];
    for (int i = 1; i <= 26; i++) cin >> c[i];
    int s[D+1][27];
    for (int i = 1; i <= D; i++) {
        for (int j = 1; j <= 26; j++) cin >> s[i][j];
    }
    int t[D+1];
    for (int i = 1; i <= D; i++) cin >> t[i];
    int last_t[27] = {};

    long long ans = 0;
    for (int i = 1; i <= D; i++) {
        ans += s[i][t[i]];
        last_t[t[i]] = i;
        for (int j = 1; j <= 26; j++) {
            ans -= c[j] * (i - last_t[j]);
        }
        cout << ans << endl;
    }
}