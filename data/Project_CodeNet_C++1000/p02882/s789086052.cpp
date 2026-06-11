#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

#define pi 3.14159265359

int main(){
    double a, b, x;
    cin >> a >> b >> x;
    double full = (a*a) * b;
    if(x >= full / 2){
        double theta = atan(2*(full-x) / (a*a*a));
        double ans = theta * 180 / pi;
        printf("%.10f", ans);
    }else{
        double theta = pi/2 - atan(2*x/(a*b*b));
        double ans = theta * 180 / pi;
        printf("%.10f", ans);
    }
    return 0;
}