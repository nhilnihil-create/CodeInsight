#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    rep(i, 1, n) {
        rep(j, i + 1, n + 1) {
            int k = 0;
            while (!((i ^ j) & (1 << k)))
                k++;
            cout << k + 1 << ' ';
        }
        cout << endl;
    }

    return 0;
}
