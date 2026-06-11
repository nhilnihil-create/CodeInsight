#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int x, res = 0;
    cin >> x;   
    int y = x / 500;
    res += 1000 * y;
    x -= 500 * y;
    y = x / 5;
    res += 5 * y;
    cout << res << endl;
    return 0;
}
