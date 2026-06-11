#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p.at(i);
    }
    int ans = 0;
    int mini = 2000000;
    for (int j : p) {
        if (min(mini, j) == j) {
            mini = j;
            ans++;
        }
    }
    cout << ans << endl;
}
