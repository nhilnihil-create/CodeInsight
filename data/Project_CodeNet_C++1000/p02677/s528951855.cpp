#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <cmath>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const double PI=3.14159265358979323846;
int main(){
    double a,b,h,m;
    cin >> a >> b >> h >> m;
    
    double theta;
    theta = 30*h - 5.5*m;
    theta = theta*PI/180;
    double c = sqrt(a*a+b*b - 2*a*b*cos(theta));
    cout << fixed << setprecision(12);
    cout <<c <<endl;
}