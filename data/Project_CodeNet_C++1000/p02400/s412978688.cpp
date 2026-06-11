#include <bits/stdc++.h>
// #include <cmath>
using namespace std;

int main() {
    double r;
    cin >> r;
    
    double area = r * r * ((double) M_PI);
    double circ = 2.0 * r * ((double) M_PI);
    cout << fixed << setprecision(5) << area << " " << circ << endl;
    return 0;
}
