#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << (#x) << ": " << (x) << endl
#define int long long

const int prize = 100000;
int x, y;

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> x >> y;

    int ans = 0;
    if(x <= 3) {
        ans += (4-x)*prize;
    }
    if(y <= 3) {
        ans += (4-y)*prize;
    }
    if(ans == prize*6) {
        ans += prize*4;
    }

    cout << ans << endl;
    
    return 0;
}
