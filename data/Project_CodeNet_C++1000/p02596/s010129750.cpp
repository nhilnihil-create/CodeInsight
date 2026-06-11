#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
    int k; cin >> k;
    int cnt = 0;
    int sev = 0;
    rep(i, k) {
        sev = (sev * 10 + 7) % k;
        cnt += 1;
        if (sev % k == 0) {
            cout << cnt << endl;
            return 0;
        } 
    }
    cout << -1 << endl;
}