#include <bits/stdc++.h>

using namespace std;

const int N = 2010, mod = 1e9 + 7;

long long d[N];

int main() {
    int n;
    cin >> n;
    d[3] = 1;
    for (int i = 4; i <= n; ++i) {
        d[i] = (d[i - 1] + d[i - 3]) % mod;    
    }
    cout << d[n] << '\n';
    return 0;
}