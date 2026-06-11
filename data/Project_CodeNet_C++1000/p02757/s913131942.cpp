#include <iostream>
using namespace std;

int main() {
    int n, p; cin >> n >> p;
    string s; cin >> s;

    long long ans = 0;
    if (p == 2 || p == 5) {
        for (int i = 0; i < n; i++) {
            if ((s[n-i-1] - '0') % p == 0) ans += n - i;
        }
    }
    else {
        long long val[p] = {};
        long long dig = 1;
        long long cur = 0;
        val[cur]++;
        for (int i = 0; i < n; i++) {
            cur = (cur + (s[n-i-1] - '0') * dig) % p;
            dig = dig * 10 % p;
            val[cur]++;
        }
        for (int i = 0; i < p; i++) ans += val[i] * (val[i] - 1) / 2;
    }
    cout << ans << endl;
}