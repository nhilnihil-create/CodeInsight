#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> n >> m;
    int all = 0;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x.at(i);
        all += x.at(i);
    }

    sort(x.begin(), x.end());
    reverse(x.begin(), x.end());

    if (x.at(m - 1) * 4 * m < all) {
        cout << "No" << endl;
    }
    else cout << "Yes" << endl;
}