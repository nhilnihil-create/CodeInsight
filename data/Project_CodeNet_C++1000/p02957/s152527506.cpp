#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int a, b;  cin >> a >> b;
    if ((a + b) % 2) cout << "IMPOSSIBLE" << endl;
    else cout << (a + b) / 2 << endl;
}
