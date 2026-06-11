#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)

int main() {
    ll H, W;
    cin >> H >> W;

    if(H == 1 || W == 1) {
        cout << 1 << endl;
    } else {
        cout << (H * W + 1) / 2 << endl;
    }

    return 0;
}