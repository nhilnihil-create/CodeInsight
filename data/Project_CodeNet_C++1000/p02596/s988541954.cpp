#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int k; cin >> k;
    int ans = -1;
    int now = 7;
    for (int i = 1; i <= k+10; i++) {
        if (now % k == 0) {
            ans = i;
            break;
        }
        else {
            now = 10 * now + 7;
            now %= k;
        }
    }
    cout << ans << endl;
    return 0;
}