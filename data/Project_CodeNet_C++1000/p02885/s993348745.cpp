#include <bits/stdc++.h>

using namespace std;

int a, b;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> a >> b;
    cout << (a - b * 2 < 0 ? 0 : a - b * 2) << '\n';

    return 0;
}