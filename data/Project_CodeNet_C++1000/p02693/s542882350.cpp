#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int k, a, b; cin >> k >> a >> b;
    bool can = false;
    for (int i = a; i <= b; i++) {
        if (i % k == 0) can = true;
    }
    if (can) cout << "OK" << endl;
    else cout << "NG" << endl;
    return 0;
}