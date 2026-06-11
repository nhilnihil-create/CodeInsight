#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int res;
    for (int i = 1; i <= 3; i++) {
        if (i != a && i != b) res = i;
    }

    cout << res << endl;

    return 0;
}
