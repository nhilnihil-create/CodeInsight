#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << (#x) << ": " << (x) << endl
#define int long long

int h, w, n;

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> h >> w >> n;

    int mx = max(h, w);
    int ans = (n+mx-1)/mx;

    cout << ans << endl;
    
    return 0;
}
