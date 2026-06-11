#include <bits/stdc++.h>
using namespace std;

int mp[4] = {0, 3, 2, 1};

int main() {
    int x, y; cin >> x >> y;
    if(x == 1 && y == 1) cout << 1000000 << endl;
    else {
        int ans = 0;
        if(x < 4) ans += mp[x];
        if(y < 4) ans += mp[y];
        cout << ans*100000 << endl;
    }
}