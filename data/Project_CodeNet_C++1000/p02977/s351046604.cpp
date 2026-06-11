#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 1 ^ 2n ^ 2n+1 = 0

// 2^i <= x を満たす最大の i
int log_x(int x){
    return 31 - __builtin_clz(x);
}

int main() {
    int N;
    cin >> N;
    int t = __builtin_ctz(N);
    int m = N >> t;
    if (m == 1) {
        cout << "No" << "\n";
        return 0;
    }
    cout << "Yes" << "\n";
    int ub = N;
    if (N % 2 == 0) {
        ub--;
    }
    for (int i = 2; i <= ub; ++i) {
        cout << 1 << " " << i << "\n";
    }
    for (int i = 2; i < ub; i += 2) {
        cout << i << " " << i+1+N << "\n";
        cout << i+1 << " " << i+N << "\n";
    }
    // 余った1+Nは任意のi+Nと繋げてよい
    cout << 1+N << " " << 2+N << "\n";
    if (N != ub) {
        int k = 1 << log_x(N);
        cout << k << " " << N << "\n";
        k = k ^ N ^ 1;
        cout << k << " " << N+N << "\n";
    }
    return 0;
}