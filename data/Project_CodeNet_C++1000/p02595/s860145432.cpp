#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
typedef long long int ll;

int main() {
        ll n, d, x, y, ans;
        ans = 0;
        cin >> n >> d;
        rep(i,n) {
                cin >> x >> y;
                if (x*x+y*y <= d*d) {
                        ++ans;
                }
        }
        cout << ans << endl;
}