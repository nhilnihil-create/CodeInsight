#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const double eps = 1e-18;
double DegreeToRadian(double degree){
return degree * M_PI / 180.0;
}

lli a, b, h, m;

int main(void){
    cin >> a >> b >> h >> m;
    double th;
    if(60*h < 11*m){
        th = DegreeToRadian((11*m-60*h)/2.0)+eps;
    }else{
        th = DegreeToRadian((60*h-11*m)/2.0)+eps;
    }
    double ans = sqrt(a*a+b*b-2*a*b*cos(th))+eps;
    cout << fixed << setprecision(10);
    cout << ans << endl;
    return 0;
}
