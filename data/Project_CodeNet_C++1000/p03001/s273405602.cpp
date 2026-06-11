#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    double W, H; cin >> W >> H;
    double x, y; cin >> x >> y;
    double ans = W * H / 2;
    cout << ans << endl;
    if(x == W / 2 && y == H / 2){
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}