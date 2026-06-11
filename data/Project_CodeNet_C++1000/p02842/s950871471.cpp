#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n; cin >> n;
    for (int i = 1; i < 50000; i++)
    {
        if ((i * 108) / 100 == n) {
            cout << i << endl;
            return 0;
        }
    }

    cout << ":(" << endl;
    return 0;
}