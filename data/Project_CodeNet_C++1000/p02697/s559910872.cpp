#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> ans;
    if (n % 2) {
        for ( int a = 1, b = n; a < b; a++, b-- ) {
            ans.emplace_back(a, b);
        }
    } else {
        for ( int a = 1, b = n / 2; a < b; a++, b-- ) {
            ans.emplace_back(a, b);
        }
        for ( int a = n / 2 + 1, b = n - 1; a < b; a++, b-- ) {
            ans.emplace_back(a, b);
        }
    }
    for ( int i=0; i<m; i++ ) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
    return 0;
}