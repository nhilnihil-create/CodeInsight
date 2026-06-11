#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    double min = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
        min += a.at(i);
    }

    min = min / (4 * m);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a.at(i) >= min) cnt++;
    }

    if (cnt >= m) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }   

    return 0;
}
