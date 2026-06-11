#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
    fastIO;
    uint64_t x;
    cin >> x;

    int year = 0;
    uint64_t account = 100;
    while (true) {
        if (account >= x) {
            cout << year << endl;
            return 0;
        }
        account += account / 100;
        year++;
    }
}