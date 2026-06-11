#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll X; cin >> X;
    for (ll A = -200; A < 200; A++) {
        for (ll B = -200; B < 200; B++) {
            ll AA = A*A, BB = B*B;
            if (AA*AA*A - BB*BB*B == X) {
                cout << A << " " << B << endl;
                return 0;
            }
        }
    }       
}
