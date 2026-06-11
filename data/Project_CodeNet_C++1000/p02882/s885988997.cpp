#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cmath>
using namespace std;
typedef long long LL;
const double pi = acos(-1);
void solve1(double a,double b,double d){
    double y = a;
    double x = b - (d - b);
    //printf("d = %.10f,x = %.10f,y = %.10f\n",d,x,y);
    double angle = atan2(y,x) / pi * 180.0;
    printf("%.12f\n",90. - angle);
}
void solve2(double a,double b,double x){
    double d = (a*a*b-x)/(a*b) * 2;
    double xx = b;
    double yy = 2 * a - d;
    double angle = atan2(yy,xx) / pi * 180.0;
    printf("%.12f\n",90.-angle);
}
int main(){
    double a,b,x;
    scanf("%lf%lf%lf",&a,&b,&x);    
    double d = x / a / a;d *= 2;
    if(d >= b)solve1(a,b,d);
    else solve2(a,b,x);
    return 0;
}