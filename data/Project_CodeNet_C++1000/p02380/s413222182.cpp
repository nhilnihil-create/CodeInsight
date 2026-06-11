#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include<math.h>
#include <cmath>
#include<iomanip>
using namespace std;
int main(){
    double a, b, C;cin >> a >> b >> C;
    double rad = M_PI /180 *C;
    
    double S = a * b * sin(rad)/ 2;
    double L = sqrt(a * a + b * b -2*a*b*cos(rad)) + a + b;
    double h = 2 * S / a;
    cout << fixed << setprecision(12) << S << endl;
    cout << L << endl;
    cout << h << endl;
        return 0;
    }
            