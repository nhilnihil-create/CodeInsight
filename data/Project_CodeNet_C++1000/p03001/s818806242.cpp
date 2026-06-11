#include <iostream>
using namespace std;
int main() {
    int w, h, x, y;
    cin >> w >> h >> x >> y;
    if (2*x == w && 2*y == h) {
        cout << (double)w*(double)h/2.0 << " " << 1 << endl;
    } else {
        cout << (double)w*(double)h/2.0 << " " << 0 << endl;
    }
}