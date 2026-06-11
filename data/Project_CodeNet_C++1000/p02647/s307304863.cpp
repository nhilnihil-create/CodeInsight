#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >>n >>k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >>a[i];

    if (k>=n-1) { // TLE対策1
        for (int i = 1; i <= n; i++) cout <<n << " ";
        cout << endl;
        return 0;
    }

  	// 回答を観た（imos法：累積和による実装により、メインの計算量をO(n)にできる！）
    for (int j = 0; j < k; j++) {
        vector<int> b(n+1);

        for (int i = 0; i < n; i++) {
            int l = max(i-a[i], 0);
            int r = min(i+a[i]+1, n);
            b[l]++; b[r]--;
        }
        for (int i = 0; i < n; i++) b[i+1] += b[i];
        b.pop_back();
        if (a==b) break;

        a = b;
    }

    for (int i = 0; i < n; i++) cout <<a[i] << " ";
    cout << endl;
    return 0;
}