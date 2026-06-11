#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int a, b;
    cin >> a >> b;

    int ans = a - 2 * b;
    if (ans < 0) cout << 0 << endl;
    else cout << ans << endl;

    return 0;
}
