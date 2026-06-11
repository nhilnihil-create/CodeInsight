#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    c.at(n - 1) = -1;
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> b.at(i);
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> c.at(i);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += b.at(a.at(i) - 1);
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] - a[i] == 1) {
            sum += c[a[i] - 1];
        }
    }
    cout << sum << endl;
    return 0;
}