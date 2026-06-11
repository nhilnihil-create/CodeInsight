#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using ld = long double;

ld pi = acos(-1);
ld eps = 0.0000000001;
ld a,b,x;

ld f(ld a,ld b,ld deg){
    if(deg > pi/2 - eps){
        return 0.0;
    }

    ld ret;
    if(a * tan(deg) <= b){
        ret = a * a * b - a * a * a * tan(deg) /2;
    }else{
        ret = b * b / tan(deg) * a/2;
    }
    return ret;
}

int main(){
    cin >> a >> b >> x;
    ld ok = pi/2;
    ld ng = 0;
    rep(i,100000){
        ld mid = (ok+ng)/2;
        if(f(a,b,mid) < x) ok = mid;
        else ng = mid;
    }

    cout << fixed << setprecision(10) << ok / pi * 180 << endl;
    return 0;
}