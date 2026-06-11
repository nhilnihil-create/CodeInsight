#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define PI 3.14159265358979323846
using namespace std;

int main() {
    int k, a, b;
    cin >> k >> a >> b;
    int max = (b / k) * k;
    if (a <= max) {
        cout << "OK" << endl;
    }
    else {
        cout << "NG" << endl;
    }
}