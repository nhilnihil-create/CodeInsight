#include <bits/stdc++.h>
using namespace std;
using Int = long long;
#define rep(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; i++)
#define PUTS(x) cout << (x) << endl;
#define MOD 1000000007
int main() {
    Int n;
    cin >> n;
    Int v[3] = {0};
    Int ans = 1;
    rep(i, n) {
        Int a;
        cin >> a;
        int c = 0;
        int index = -1;
        rep(j, 3) {
            if (v[j] == a) {
                c++;
                index = j;
            }
        }
        if (c == 0) {
            puts("0");
            return 0;
        }
        ans *= c;
        ans %= MOD;
        v[index]++;
    }
    PUTS(ans)
}
