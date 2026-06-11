#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    double W,H,x,y;
    cin >> W >> H >> x >> y;
    cout << W*H/2 << " ";
    if(W/2 == x && H/2 == y) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }
}