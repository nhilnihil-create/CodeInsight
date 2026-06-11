#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    int cnt = 0, ans = 0, tmp;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        if (i == 0) {
            tmp = x;
            continue;
        }
        if (tmp >= x) {
            cnt++;
            ans = max(ans, cnt);
        } else cnt = 0;
        tmp = x;
    }
    cout << ans << endl;
}