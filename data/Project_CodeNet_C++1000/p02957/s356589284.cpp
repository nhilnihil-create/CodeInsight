#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int a, b;
    cin >> a >> b;
    if ((a + b) % 2) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << (a + b) / 2 << endl;
    }
    return 0;
}