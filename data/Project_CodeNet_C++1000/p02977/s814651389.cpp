#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n == (n & (-n))) {
        cout << "No" << endl;
        return 0;
    }
    vector<pair<int, int>> edges;
    for (int i = 2; i < n; i += 2) {
        edges.push_back(make_pair(1, i));
        edges.push_back(make_pair(i, i+1));
        edges.push_back(make_pair(1, i+1 + n));
        edges.push_back(make_pair(i+1 + n, i + n));
    }
    edges.push_back(make_pair(3, 1 + n));
    // Special case when n is even
    if (n % 2 == 0) {
        edges.push_back(make_pair((n ^ (n & (-n))) + 1 + n, n));
        edges.push_back(make_pair(n & (-n), 2*n));
    }
    cout << "Yes" << endl;
    for (auto edge : edges) {
        cout << edge.first << " " << edge.second << "\n";
    }
    return 0;
}
