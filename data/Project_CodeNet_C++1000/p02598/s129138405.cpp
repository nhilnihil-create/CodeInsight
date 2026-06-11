/**
 *    author:  FromDihPout
 *    created: 2020-08-27
**/

#include <bits/stdc++.h>
using namespace std;

long long n, k;
vector<int> a;

bool check(int len) {
    long long moves = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] <= len) break;
        moves += (a[i] - 1) / len;
    }
    return moves <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    int l = 1, r = a[n-1], ans = a[n-1];
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
