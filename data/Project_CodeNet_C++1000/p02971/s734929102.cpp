#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
        b.at(i) = a.at(i);
    }
    sort(b.begin(), b.end());
    int ans;
    for (int i = 0; i < n; i++) {
        if (a.at(i) == b.at(n - 1)) {
            ans = b.at(n - 2);
        } else {
            ans = b.at(n - 1);
        }
        cout << ans << endl;
    }
    return 0;
}