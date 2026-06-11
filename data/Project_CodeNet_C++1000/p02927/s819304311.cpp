#include <bits/stdc++.h>
#define mod 1000000007ll
using namespace std;
typedef long long ll;

int m, d, ans;
int main() {
    cin >> m >> d;
    for (int i = 22; i <= d; i++) {
        if (i % 10 < 2) {
            continue;
        }
        int k = (i / 10) * (i % 10);
        if (k <= m) {
            ans++;
        }
    }
    cout << ans << endl;
}