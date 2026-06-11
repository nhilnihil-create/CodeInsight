#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
const int mod =1'000'000'007;

int main(){
    int a, b, h, m;
    cin >> a >> b >> h >> m;
    const double pi = acos(-1);
    double th = (double)(h*60+m)/720 * 2*pi;
    double tm = (double)m/60 * 2*pi;
    double xh = a*cos(th), yh = a*sin(th);
    double xm = b*cos(tm), ym = b*sin(tm);
    double dx = xh-xm, dy = yh-ym;
    double ans = sqrt(dx*dx + dy*dy);
    printf("%.10f\n", ans);
    return 0;
}
