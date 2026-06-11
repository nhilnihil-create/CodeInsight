#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
    double a, b, x;
    cin >> a >> b >> x;
    double ans = 0;
    if(a * a * b / 2.0 >= x){
        ans = M_PI / 2.0 - atan( 2*x / (a*b*b));
    } else {
        ans = atan(2 * (a*a*b - x) / (a*a*a));
    }
    cout << setprecision(10) << 180.0 * ans / M_PI <<  endl;
    return 0;
}
