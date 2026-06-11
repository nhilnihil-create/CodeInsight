#include <bits/stdc++.h>
#define rep(i , n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
int main() {
    int W , H , x , y;
    cin >> W >> H >> x >> y;
    cout << double(W) * double(H) / 2 << " " << (x + x == W && y + y == H) << endl;
}