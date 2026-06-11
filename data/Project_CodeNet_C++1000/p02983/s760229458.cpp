#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    int L, R; cin >> L >> R;
    int M = 2019;
    if (L / 2019 == R / 2019 && L % 2019 != 0) {
        for (int X = L % 2019; X < R % 2019; X++) {
            for (int Y = X+ 1; Y <= R % 2019; Y++) {
                if ((X * Y) % 2019 < M) {
                    M = (X * Y) % 2019;
                }
            }
        }
            cout << M << endl;
        
    }
    else {
        cout << 0 << endl;
    }
}