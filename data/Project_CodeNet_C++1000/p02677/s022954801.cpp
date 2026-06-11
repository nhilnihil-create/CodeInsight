#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);
int main() {
int a,b,h,m;
cin >> a >> b >> h >> m;
double ang1 = (double)(h*60 + m)/720*2*PI;
double ang2 = (double)m/60*2*PI;
double xa = a*cos(ang1);
double ya = a*sin(ang1);
double xb = b*cos(ang2);
double yb = b*sin(ang2);
double dx = xa - xb;
double dy = ya - yb;
double d = sqrt(dx*dx + dy*dy);
printf("%.10f\n",d);

}
