#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


long double cal(long double a, long double b, long double theta){
    if(theta > PI/2.0 - EPS){
        return 0.0;
    }

    long double ret;
    if(a*tan(theta) >= b){
        return b*b/tan(theta)*a/2.0;
    }else{
        return a*a*b - a*a*a*tan(theta)/2.0;
    }
}

int main() {

    ll a,b,x; cin >> a >> b >> x;

    long double ok = PI/2.0;
    long double ng = 0.0;
    rep(i,100000){
        long double mid = (ok + ng)/2.0;
        if(cal(a,b,mid) < x) ok = mid;
        else ng = mid;
    }
    cout << fixed << setprecision(10) << ok/PI*180 << endl;
    return 0;
}
