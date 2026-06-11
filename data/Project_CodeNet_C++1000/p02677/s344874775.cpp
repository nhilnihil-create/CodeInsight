#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_in_out  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const double pi = acos(-1);

int main()
{
    fast_in_out;
    int a,b,h,m;
    cin >> a >> b >> h >> m;
    double angleHour1 = pi * (1.0 / 6) * h;
    double angleHour2 = pi * (1.0 / 360) * m;
    double angleMin = pi * (1.0 / 30) * m;
    double c = a * a;
    c += (b * b);
    c -= (2 * a * b * cos(angleHour1 + angleHour2 - angleMin));
    printf("%.20lf",sqrt(c));
}
