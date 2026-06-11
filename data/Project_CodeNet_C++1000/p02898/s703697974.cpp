#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
int n, x, k, res;
int main() {
    DAU
    cin >> n >> k;
    while (n--) {
        cin >> x;
        res += (x >= k);
    }
    cout << res;
    PLEC
}
