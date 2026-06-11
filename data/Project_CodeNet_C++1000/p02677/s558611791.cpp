#include <bits/stdc++.h>
#define ll long long
#define ar array
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int M = 1e9+7;
const int N = 2*1e5;
#define PI 	3.14159265358979323846


int main(){
    AC
    int a, b, h, m;
    cin>>a>>b>>h>>m;
    int mm = h*60+m;
    double hour_deg = 0.5 * mm;
    double min_deg = 6*m;
    double d = min(abs(hour_deg-min_deg), abs(min_deg-hour_deg));
    double tmp = a*a+b*b;
    double dist = sqrt(tmp-2*a*b*cos(d*PI/180.0));
    cout<<setprecision(17)<<dist<<endl;

}