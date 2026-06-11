#include <bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int M; cin >> M;
    LL n = 0, sum = 0;
    for (int i = 0; i < M; ++i) {
        int di; LL ci; cin >> di >> ci;
        n += ci;
        sum += di * ci;
    }
    cout << (sum-1) / 9 + n-1 << endl;
    return 0;
}
