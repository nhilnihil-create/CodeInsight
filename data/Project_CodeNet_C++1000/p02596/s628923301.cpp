#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
    int K;
    int64_t ans = 1;
    int64_t x = 0;
    cin >> K;
    unordered_set<int> a;
    while (true) {
        x = (10 * x + 7) % K;

        if (a.count(x)) {
            cout << -1 << endl;
            exit(0);
        }
        a.insert(x);
        if (x == 0) {
            cout << ans << endl;
            exit(0);
        }

        ans++;
    }
}
