#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(n,0);
    int tmp;
    for (int i = 0; i < q; i++) {
        cin >> tmp;
        a.at(tmp-1)++;
    }

    for (int i = 0; i < n; i++) {
        if (k - q + a.at(i) > 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
