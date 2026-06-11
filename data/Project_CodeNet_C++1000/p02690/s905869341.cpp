#include <bits/stdc++.h>
#define int long long
#pragma GCC optimize("O3,Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,sse")
using namespace std;

int root(int x) {
    for (int i = -1000; i <= 1000; i++) {
        if (i * i * i * i * i == x) {
            return i;
        }
    }
    return -1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x;
    cin >> x;
    for (int i = -1000; i <= 1000; i++) {
        int res = i * i * i * i * i - x;
        if (root(res) != -1) {
            cout << i << ' ' << root(res) << endl;
            return 0;
        }
    }

    fflush(stdout);
    return 0;
}
