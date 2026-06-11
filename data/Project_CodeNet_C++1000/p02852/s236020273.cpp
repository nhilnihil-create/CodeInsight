#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int base = n;
    int current_count = 0;
    vector<int> counts(n + 1, -1);
    counts[n] = 0;
    while (base > 0) {
        current_count++;
        int mn = -1;
        for (int i = 1; i <= m; i++) {
            if (base - i >= 0 && s[base - i] == '0') {
                counts[base - i] = current_count;
                mn = base - i;
            }
        }
        if (mn < 0) {
            cout << -1 << endl;
            return 0;
        }
        base = mn;
    }
    current_count--;
    int cur = 0;
    for (int i = 0; i <= n; i++) {
        if (counts[i] == current_count) {
            cout << i - cur << " ";
            cur = i;
            current_count--;
        }
    }
    return 0;
}
