#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a.at(i) = make_pair(x, i);
    }
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++) {
        cout << a.at(i).second;
        if (i < n) cout << " ";
    }
    return 0;
}