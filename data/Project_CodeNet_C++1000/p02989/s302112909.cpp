#include <bits/stdc++.h>
using namespace std;


void solve () {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int mid = n / 2;
    cout << a[mid] - a[mid - 1];

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
