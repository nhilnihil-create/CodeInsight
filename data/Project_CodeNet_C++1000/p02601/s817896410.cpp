#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int cnt = 0;
    while (a >= b) {
        b *= 2;
        cnt++;
    }
    while (b >= c) {
        c *= 2;
        cnt++;
    }
    if (cnt <= k) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}