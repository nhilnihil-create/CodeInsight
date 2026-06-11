#include <iostream>
#include <map>
using namespace std;

int main() {
    using Int = long long;
    
    Int t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    
    Int d1 = t1 * (b1 - a1);
    Int d2 = t2 * (b2 - a2);
    
    if (d1 + d2 == 0) {
        cout << "infinity" << endl;
        return 0;
    }
    
    if (d1 < 0) {
        d1 *= -1;
        d2 *= -1;
    }
    
    if (d1 + d2 > 0) {
        cout << 0 << endl;
        return 0;
    }
    
    Int m = -(d1 + d2);
    
    if (d1 % m == 0) {
        cout << 2 * (d1 / m) << endl;
    } else {
        cout << 2 * (d1 / m) + 1 << endl;
    }
}