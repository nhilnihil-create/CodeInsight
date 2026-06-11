#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using llint = long long int;
using namespace std;

int main() {
    fastIO;
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    int tap = 1;
    while (true) {
        if (b <= tap)
            break;
        tap = tap - 1 + a;
        cnt++;
    }
    // cout << tap << endl;
    cout << cnt << endl;
}