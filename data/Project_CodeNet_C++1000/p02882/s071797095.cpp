#include <iostream>
#include <cmath>
#include <string.h>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define INF 100000000;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const double eps = 1.0e-14;
const double PI = (acos(-1));
int main(){
    double a,b,x;
    cin >> a >> b >> x;
    double space = b - (x / (a*a));
    //cout << space << endl;
    double ans = atan( a / ( 2 * space ));
    if(2 * space > b){
        double c = (2 * x) / (b * a);
        ans = atan(c / b);
    }
    ans *= 180 / PI;
    ans = 90 - ans;
    printf("%.10f",ans + eps);
}