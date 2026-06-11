#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MAX_P = 10000;

ll nums[MAX_P + 5];

int main() {
    int n, p;
    string s;
    cin >> n >> p >> s;
    if (p == 2) {
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if ((s[i] - '0') % 2 == 0) ans += i + 1;
        }
        cout << ans << endl;
        return 0;
    }
    if (p == 5) {
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if ((s[i] - '0') == 0 || (s[i] - '0') == 5) ans += i + 1;
        }
        cout << ans << endl;
        return 0;
    }
    ll num = 0, t = 1;
    nums[0] = 1;
    for (int i = n - 1; i >= 0; i--, t *= 10) {
        t %= p;
        num = (num + (s[i] - '0') * t) % p;
        nums[num]++;
    }
    ll ans = 0;
    for (int i = 0; i < MAX_P; i++) {
        ans += nums[i] * (nums[i] - 1) / 2;
    }
    cout << ans << endl;
}