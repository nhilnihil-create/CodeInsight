#include <bits/stdc++.h>
using namespace std;

int main() {
    int M; cin >> M;
    int64_t keta = 0, sum = 0;
    for(int i = 0; i < M; ++i) {
        int64_t d, c; cin >> d >> c;
        keta += c;
        sum += d * c;
    }
    int64_t ans = keta + (sum - 1) / 9 - 1;
    cout << ans << '\n';
    return 0;
}
