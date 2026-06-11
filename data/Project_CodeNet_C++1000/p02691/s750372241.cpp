#include <bits/stdc++.h>
#define int long long
#pragma GCC optimize("O3,Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,sse")
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    map<int, int> a;
    map<int, int> b;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        a[i - arr[i]]++;
        b[i + arr[i]]++;
    }
    int tot = 0;
    for (int i = 1; i <= 4e5; i++) {
        tot += a[i] * b[i];
    }
    cout << tot << '\n';

    fflush(stdout);
    return 0;
}
