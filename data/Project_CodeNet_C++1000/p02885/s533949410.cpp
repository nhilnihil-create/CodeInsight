#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int a, b;
    cin >> a >> b;

    if (a < 2*b) cout << 0 << endl;
    else if (a >= 2*b) cout << a-2*b << endl;

    return 0;
}