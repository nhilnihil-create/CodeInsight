#include <iostream>
#include <iomanip>
using namespace std;
using ll = long long int;
int main() {
    double W, H, x, y;
    cin >> W >> H >> x >> y;


    cout << fixed << setprecision(10) << (W * H)/2.0 << " " << (x == (W / 2.0) && y == (H / 2.0)? 1 : 0) << endl;
}