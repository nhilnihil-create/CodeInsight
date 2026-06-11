#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)
//cout << std::fixed << std::setprecision(15) << y << endl;


#define PI 3.141592653589793

double r2d(double radian){
    return radian * 180.0 / PI;
}

int main(){
    double a, b, x;
    cin >> a >> b >> x;

    double ans;
    if(x <= (a * a * b) / 2.0){
        double bottomWidth = (2.0 * x) / (a * b);
        ans = r2d(atan(b / bottomWidth)); 
    }else{
        double centerHeight = x / (a * a);
        ans = r2d(atan(((b - centerHeight) * 2.0) / a));
    }

    cout << std::fixed << std::setprecision(15) << ans << endl;


    return 0;
}
