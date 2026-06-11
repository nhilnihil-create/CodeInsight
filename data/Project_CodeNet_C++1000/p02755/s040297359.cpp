#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, ans = -1;
    cin >> a >> b;
    for (int i = 1; i <= 1009; i++) {
        if (floor(i * 0.08) == a) {
            if (floor(i * 0.1) == b) {
                ans = i;
                break;
            }
        }
    }
    cout << ans << endl;
}
