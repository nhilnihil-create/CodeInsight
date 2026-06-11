#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int numberOfDigits (int x) {
    int nod = 0;
    int tmp = x;
    while (1) {
        tmp /= 10;
        nod++;
        if (tmp == 0) break;
    }
    return nod;
}

bool checkDigit (int m, int nod, int x, int s[], int c[]) {
    int digit;
    rep (i, m) {
        int tmp = x;
        for(int j = 0; j < nod - s[i] + 1; j++) {
            digit = tmp % 10;
            tmp /= 10;
        }
        if (digit != c[i]) return true;
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    int s[m+10], c[m+10];
    rep(i, m) cin >> s[i] >> c[i];

    int ans = 0;
    for (int x = 0; x < 1001; x++) {
        if (x == 1000) {
            cout << -1 << endl;
            return 0;
        }
        int nod = numberOfDigits(x);
        if (nod != n) continue;
        if (checkDigit(m, nod, x, s, c)) continue;
        ans = x; break;
    }

    cout << ans << endl;

    return 0;
}