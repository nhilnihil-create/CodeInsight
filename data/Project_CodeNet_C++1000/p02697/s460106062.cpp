
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    if (m & 1) {
        for (int i = 1; i <= m / 2; ++i) {
            cout << i << ' ' << m + 1 - i << endl;
        }
        for (int i = 1; i <= (m + 1) / 2; ++i) {
            cout << m + i << ' ' << (m + 1) * 2 - i << endl;
        }
    } else {
        for (int i = 1; i <= m / 2; ++i) {
            cout << i << ' ' << m + 2 - i << endl;
        }
        for (int i = 1; i <= m / 2; ++i) {
            cout << m + 1 + i << ' ' << (m + 1) * 2 - i << endl;
        }
    }

    return 0;
}

