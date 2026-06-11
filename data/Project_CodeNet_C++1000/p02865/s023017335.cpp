#include <bits/stdc++.h>
#define fastio (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
    fastio;
    int n;
    cin >> n;

    int sum = 0;
    for (int i = 1; i < n / 2 + (n % 2); i++) {
        sum++;
    }
    cout << sum << endl;
}