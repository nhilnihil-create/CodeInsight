#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int lim = (n - 1) * (n - 2) / 2;
    if (k > lim) {
        printf("-1");
        return 0;
    }
    int diff = lim - k;
    int m = n - 1 + diff;
    vector<pair<int, int>> edges;
    for (int i = 1; i < n - 1; i++) {
        for (int k = i + 1; k < n; k++) {
            edges.emplace_back(make_pair(i, k));
        }
    }
    cout << m << endl;
    for (int i = 1; i < n; i++) {
        cout << i << " " << n << endl;
    }
    for (int i = 0; i < diff; i++) {
        cout << edges[i].first << " " << edges[i].second << endl;
    }
    return 0;
}
