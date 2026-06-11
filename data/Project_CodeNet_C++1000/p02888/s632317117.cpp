/**
 *    author:  FromDihPout
 *    created: 2020-08-09
**/

#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = a[i] + a[j];
            int l = j + 1, r = n;
            while (l < r) {
                int mid = (l + r) / 2;
                if (a[mid] >= sum) {
                    r = mid;
                }
                else {
                    l = mid + 1;
                }
            }
            ans += r - j - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}