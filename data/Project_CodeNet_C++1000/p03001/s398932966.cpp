#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    long double h,w,x,y;
    cin >> w >> h >> x >> y;

    cout << fixed << setprecision(10);
    cout << (h*w) / 2.0 << " ";
    cout << (x*2==w && y*2==h) << endl;
}
