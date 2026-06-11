#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    ll W, H, x, y;
    cin >> W >> H >> x >> y;

    double area = W * H;
    double centX = W * 0.5;
    double centY = H * 0.5;

    if(W%2 == 0 && H % 2== 0 && x == W/2 && y == H/2){
        cout <<fixed << setprecision(10) << area * 0.5 << ' ' << 1 << endl;
    } else {
         cout <<fixed << setprecision(10)<< area * 0.5 << ' ' << 0 << endl;
    }

    return 0;
}
