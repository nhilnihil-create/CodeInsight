#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    cout << max(0, a - 2 * b) << endl;
}
