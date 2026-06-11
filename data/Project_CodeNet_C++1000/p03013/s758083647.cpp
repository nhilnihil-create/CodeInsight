#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

long p = 1000000007;
vector<long> f(100001, -1);

int main() {
    int n, m;
    cin >> n >> m;
    rep(i, m) {
        int a;
        cin >> a;
        f[a] = 0;
    }
    rep(i, n+1) {
        // if (i == 0) continue;
        // if (i == 1 && f[i] == -1) {
        //     f[1] = 1;
        //     continue;
        // }
        // if (i == 2 && f[i] == -1) {
        //     f[2] = f[1] + 1;
        //     continue;
        // }
        // if (f[i] == -1) f[i] = (f[i-1] + f[i-2]) % p;
        if (i == 0) continue;
        else if (i == 1 && f[i] == -1) f[1] = 1;
        else if (i == 2 && f[i] == -1) f[2] = f[1] + 1;
        else if (f[i] == -1) f[i] = (f[i-1] + f[i-2]) % p;
    }
    cout << f[n] << endl;
}