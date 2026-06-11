#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; (i) < ((int)(n)); ++(i))

int main() {
    int ans = 0;
    int A, B;
    cin >> A >> B;
    ans = (A + B) / 2;
    if(abs(A - ans) == abs(B - ans))
        cout << ans << endl;
    else
        cout << "IMPOSSIBLE" << endl;
}