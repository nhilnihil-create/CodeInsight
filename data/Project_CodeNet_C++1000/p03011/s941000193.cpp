#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int p, q, r;
    cin >> p >> q >> r;

    int ma = min(p + q, r + q);
    int mb = min(q + r, p + r);
    int mc = min(r + p, q + p);
    
    cout << min(ma, min(mb, mc)) << endl;

}