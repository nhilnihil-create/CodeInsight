// ABC159-D Banned K

#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, a[200001];
    long long sum[200001] = {}, ans, all;

    cin >> n;
    for(int i=0 ;i<n ;i++ ) {
        cin >> a[i];
        sum[a[i]] ++;
    } 

    all = 0;
    for(int i=1 ;i<=n ;i++ ) {
        ans = sum[i];
        all += ans * (ans - 1) / 2;
    }

    for(int i=0 ;i<n ;i++ ) {
        ans = sum[a[i]];
        ans = ans * (ans - 1) / 2;
        cout << all - ans + (sum[a[i]] - 1) * (sum[a[i]] - 2) / 2 << '\n';
    }
    return (0);
}