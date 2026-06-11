#include<iostream>
#include<math.h>
using namespace std;
int main() {
    double r;
    cin >> r;
    double area = r * double (r) * M_PI;
    double circ = 2 * double (r) * M_PI;
    cout << fixed << area << " " << fixed << circ << endl;
    return 0;
}
