#include <bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處

int main() {
    LL t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    // 調整成 a1 < b1
    if (a1 > b1) {
        swap(a1, b1);
        swap(a2, b2);
    }
    LL A1 = t1 * a1;
    LL A2 = t2 * a2;
    LL B1 = t1 * b1;
    LL B2 = t2 * b2;
    LL A = A1 + A2;
    LL B = B1 + B2;
    if (A < B) {
        cout << 0 << endl;
        return 0;
    } else if (A == B) {
        cout << "infinity" << endl;
        return 0;
    } else {
        LL x = (B1 - A1) / (A - B) + 1;
        // printf("ans = %lld\n", ans);
        LL ans = x * 2 - 1;
        if ((B1 - A1) % (A - B) == 0) {
            ans--;
        }
        cout << ans << endl;
    }
}
