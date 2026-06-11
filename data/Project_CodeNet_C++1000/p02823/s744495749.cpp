#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    Int n, a, b; cin >> n >> a >> b;
    n;
    a--;
    b--;

    if ((b-a)%2 == 0) {
        cout << (b-a)/2 << endl;
    }
    else {
        Int ans = 0;
        ans = min(a, n-1-b)+1 + (b-a-1)/2;
        cout << ans << endl;
    }
}