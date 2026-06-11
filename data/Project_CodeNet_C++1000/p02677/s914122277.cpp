#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cmath>
#define endl "\n"
#define PI 3.14159265358979323846264338327950L
typedef long long int ll;
typedef unsigned long long int ull;
typedef float f;
using namespace std;

void solve()
{   int a,b,h,m,s,ma; cin >> a >> b >> h >> m; long double ha,da;
    s=60*h+m; ha=((long double)s/2);ma=((long double)6*s);
    if (ha>=ma) da=ha-ma; else da=ma-ha;
    long double dar=(long double)(da*PI)/180;
    long double ans=sqrt((long double)(a*a+b*b)-(long double)2*a*b*cos(dar));
    cout.setf(ios::fixed); cout.precision(20);
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
