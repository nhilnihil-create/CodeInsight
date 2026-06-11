#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int a, b;
    cin >> a >> b;

    if ((abs(a+b)%2) != 0) cout << "IMPOSSIBLE" << endl;
    else if (abs(a+b)%2 == 0) cout << abs(a+b)/2 << endl;

    return 0;
}