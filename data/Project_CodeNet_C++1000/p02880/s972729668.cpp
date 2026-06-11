#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n;
    cin >> n;
    map<int, bool> tbl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            tbl[(i + 1) * (j + 1)] = true;
        }
    }
    string ans = "No";
    if (tbl.count(n)) {
        ans = "Yes";
    }
    cout << ans << endl;
    return 0;
}