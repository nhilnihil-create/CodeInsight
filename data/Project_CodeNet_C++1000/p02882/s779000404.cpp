#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

template<typename T>
istream& operator>> (istream& is, vector<T> &vec){
    for(T& x: vec) is >> x;
    return is;
}

int main(){
    ll a, b, x;
    cin >> a >> b >> x;
    double height = x / (double)(a * b) * 2;
    double balpha = 0, bb = (double)b;
    if(height > a){
        balpha = (2 * (x / (double)a) / (double)a) - b;
        bb -= balpha;
        //printf("%.6lf %.6lf %.6lf\n", balpha, bb, height);
        height = a;
    }
    double ratio = height/(double)bb;
    double theta = atan(ratio);
    double thetadeg = theta * 360.0 / (2 * PI);
    //printf("%.6lf\n", height);
    //printf("%.6lf\n", ratio);
    //printf("%.6lf\n", theta);
    printf("%.6lf\n", 90 - thetadeg);
    return 0;
}