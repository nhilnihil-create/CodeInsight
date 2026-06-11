#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, a[100100], d[100100];
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int sum = 0, evensum = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
        if (i % 2 == 0) evensum += a[i];
    }
    d[1] = sum - (evensum * 2); 
    for(int i = 2; i <= n; ++i) {
        d[i] = a[i-1] * 2 - d[i-1];
    }
    for(int i = 1; i <= n; ++i) {
        cout << d[i] << ' ';
    }
}
