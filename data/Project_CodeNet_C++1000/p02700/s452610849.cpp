#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define PI 3.14159265358979323846
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((a + d - 1) / d >= (c + b - 1) / b) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    
}