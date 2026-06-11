#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int psum[2001];
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < 2001; i++) psum[i] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        psum[a[i]]++;
    }
    for (int i = 1; i < 2001; i++) psum[i] += psum[i-1];
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int r = a[i]+a[j]-1;
            int l = max(a[i],a[j])-min(a[i],a[j])+1;
            res += psum[r]-psum[l-1];
            if (a[i] >= l && a[i] <= r) res--;
            if (a[j] >= l && a[j] <= r) res--;
        }
    }
    cout << res/3 << '\n';
}
/*

 */