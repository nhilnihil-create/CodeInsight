#include <bits/stdc++.h>
using namespace std;
const double pi =acos(-1);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double a,b,h,m;
    cin>>a>>b>>h>>m;
    m = m/60;
    h=h/12;
    double goc = (h+m/12-m)*2*pi;
    double S = sqrt(a*a+b*b-2*a*b*cos(goc));
    printf("%.20f", S);
    return 0;
}