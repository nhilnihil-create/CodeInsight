#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    int max1 = 0, max2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
        if (a.at(i) > max1) {
            max2 = max1;
            max1 = a.at(i);
        } else if (a.at(i) == max1 || a.at(i) > max2) {
            max2 = a.at(i);
        }
    }

    for (int i = 0; i < n; i++) {
        if (a.at(i) == max1) {
            cout << max2 << endl;
        } else {
            cout << max1 << endl;
        }
    }

    return 0;
}
