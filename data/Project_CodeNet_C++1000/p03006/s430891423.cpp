#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int x[n], y[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    map<pair<int, int>, int> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            pair<int, int> p = make_pair(x[i] - x[j], y[i] - y[j]);
            d[p] += 1;
        }
    }
    int counter = 0;
    for (auto it = d.begin(); it != d.end(); it++) {
        counter = max(counter, (*it).second);
    }
    cout << n - counter << endl;
    return 0;
}
