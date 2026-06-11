#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    int h1, m1, h2, m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    int start = h1 * 60 + m1;
    int end = h2 * 60 + m2;
    cout << (end - start - k) << endl;
}