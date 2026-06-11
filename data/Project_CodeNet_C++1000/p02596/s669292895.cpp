#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void run() {
    int k;
    cin >> k;
    int x = 0;
    for (int i = 1; i <= 2000000; i++) {
        x = (x * 10 + 7) % k;
        if (x == 0) {
            cout << i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    run();
    return 0;
}
