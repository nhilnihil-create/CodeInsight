#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    int s1 = w[0], s2 = 0;
    for (int i = 1; i < n; i++) {
        s2 += w[i];
    }
    int min_abs = abs(s1 - s2);
    for (int i = 1; i < n; i++) {
        s1 += w[i];
        s2 -= w[i];
        min_abs = min(min_abs, abs(s1 - s2));
    }
    cout << min_abs << endl;
    return 0;
}