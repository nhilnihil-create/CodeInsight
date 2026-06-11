// C - :(Colon)
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    long double a, b, h, m;
    cin >> a >> b >> h >> m;
    long double ans = 0.0;
    long double longhand = m*6;
    long double shorthand = (h*60+m)*360/(12*60);
    long double handangle = shorthand - longhand;
    long double x = handangle*(M_PI/180);
    ans = a*a + b*b - 2*a*b*cos(x);
    cout << fixed << setprecision(20) << sqrt(ans) << endl; 
    return 0;
}