#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll W, H, x, y;
    cin >> W >> H >> x >> y;
    int ans = 0;
    if (2 * y - H == 0 && 2 * x - W == 0)
    {
        ans++;
    }
    
    cout << setprecision(27) << (long double)W * H /2 << " " << ans << endl;

  return 0;
}
