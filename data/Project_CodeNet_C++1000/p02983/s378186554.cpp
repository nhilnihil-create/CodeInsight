#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll L, R;
    cin >> L >> R;

    if(R - L > 2018) {
        cout << 0 << endl;
    } else if(R%2019 <= L%2019) {
        cout << 0 << endl;
    } else {
        int ans = 2020;
        for(int i = L%2019; i <= R%2019; i++) {
            for(int j = i + 1; j <= R%2019; j++) {
                ans = min(ans, (i*j)%2019);
            }
        }
        cout << ans << endl;
    }


    return 0;
}