#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC return 0;
using namespace std;
int freq[10005], n, p, p10(1), curr;
long long res;
string s;
int main() {
    DAU
    cin >> n >> p >> s;
    if (p == 2 || p == 5) {
        for (int i = 0; i < n; ++i)
            if ((s[i] - '0') % p == 0)
                res += i + 1;
        cout << res;
        PLEC
    }
    reverse(s.begin(), s.end());
    freq[0] = 1;
    for (const char& ch : s) {
        curr = (curr + p10 * (ch - '0')) % p;
        res += freq[curr];
        ++freq[curr];
        p10 = (10 * p10) % p;
    }
    cout << res;
    PLEC
}
