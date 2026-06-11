#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p.at(i);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (p.at(i) != i + 1) {
            cnt++;
        }
    }
    string ans = "YES";
    if (cnt > 2) {
        ans = "NO";
    }
    cout << ans << endl;
    return 0;
}