#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


signed main() {
    int A, B;
    cin >> A >> B;

    int ans = -1;
    for (int i=1; i<=1009; i++) {
        int a = (i *  8) / 100;
        int b = (i * 10) / 100;
        if ((a == A) && (b == B)) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}
