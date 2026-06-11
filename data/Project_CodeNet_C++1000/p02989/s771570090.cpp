#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> dn(n);
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;

        dn.at(i) = d;
    }

    sort(dn.begin(), dn.end());

    int c = n / 2;
    int k = dn.at(c), kp = dn.at(c - 1);

    if (k == kp) {
        cout << 0 << endl;
        return 0;
    }

    cout << (k - kp) << endl;
}
