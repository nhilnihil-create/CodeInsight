#include <math.h>

#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n;
    m = n / 10 * 10;
    m = n - m;
    if (m == 3) {
        cout << "bon" << endl;
    } else if (m == 0 || m == 1 || m == 6 || m == 8) {
        cout << "pon" << endl;
    } else {
        cout << "hon" << endl;
    }
    return 0;
}