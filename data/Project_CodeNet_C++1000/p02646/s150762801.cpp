#include <iostream>
#include <vector> 
#include <cmath>
using namespace std;

#define int long long

signed main() {
    int a, v, b, w, t;
    cin >> a >> v >> b >> w >> t;

    if(a < b && a + t * v >= b + t * w) {
        cout << "YES" << endl;
        return 0;
    } else if(a > b && a - t * v <= b - t * w) {
        cout << "YES" << endl;
        return 0;
    }

    cout << "NO" << endl;
    return 0;
}