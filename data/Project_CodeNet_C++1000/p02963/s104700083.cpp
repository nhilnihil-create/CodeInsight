#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll S;
    cin >> S;
    ll X1 = sqrt(S);
    ll Y2 = X1;
    while (X1 * Y2 < S) {
        if (X1 < 1e9) X1++;
        else Y2++;
    }
    ll X2 = X1 * Y2 - S;
    cout << X1 << ' ' << 1 << ' ' << X2 << ' ' << Y2 << ' ' << 0 << ' ' << 0 << '\n';
}