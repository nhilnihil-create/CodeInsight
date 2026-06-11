#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    double x1, x2, y1, y2, distance;
    cin >> x1 >> y1 >> x2 >> y2;
    distance = sqrt(pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0));
    cout << setprecision(20) << distance << endl;
    return 0;
}