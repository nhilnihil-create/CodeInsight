#include <iostream>
using namespace std;

int prime[123457 * 2], n, cnt;

void solve() {
    prime[0] = prime[1] = 1;
    for (int i = 2; i <= 123456 * 2; ++i) {
        if (prime[i] == 0) {
            for (int j = 2; i * j <= 123456 * 2; ++j) {
                prime[i * j] = 1;
            }
        }
    }
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();

    while (cin >> n, n) {
        cnt = 0;
        for (int i = n+1; i <= 2 * n; ++i) {
            if (i > 123456 * 2) break;
            if (prime[i] == 0) cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}