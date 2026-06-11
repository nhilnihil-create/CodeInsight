#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

const double PI = acos(-1.0);

int main(){
    int a,b,h,m;
    cin >> a >> b >> h >> m;
    double ha = (double)(h*60 + m)/720*(PI*2);
    double ma = (double)m/60*(PI*2);
    double angle = ha - ma;
    double ans = sqrt(a*a+b*b-2.0*a*b*cos(angle));
    cout << fixed << setprecision(10) << ans << endl;
}