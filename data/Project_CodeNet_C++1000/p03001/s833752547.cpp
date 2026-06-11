#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    double W, H, x, y;
    cin >> W >> H >> x >> y;
    double size_ = W / 2 * H;
    cout << std::fixed << std::setprecision(15) << size_ << " ";
    if (x * 2 == W && 2 * y == H) {
        cout << "1";
    } else {
        cout << "0";
    }

    cout << endl;
    return 0;
}