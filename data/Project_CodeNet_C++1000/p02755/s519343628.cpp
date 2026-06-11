#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int a, b;
    cin >> a >> b;
    int v = 0;
    for (int i = 0; i < 10005; i++) {
        if ((i * 8 / 100 == a) && (i / 10 == b)) {
            v = i;
            break;
        }
    }
    if (v == 0) {
        cout << -1 << endl;
    } else {
        cout << v << endl;
    }
    return 0;
}