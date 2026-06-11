#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

static int syokin(int a) {
    if (a == 1)
        return 300000;
    else if (a == 2)
        return 200000;
    else if (a == 3)
        return 100000;
    else
        return 0;
}
int main() {
    int x, y; cin >> x >> y;
    int ans = 0;

    ans += syokin(x);
    ans += syokin(y);

    if (x == 1 && y == 1)
        ans += 400000;
    
    cout << ans << endl;
    
    return 0;
}