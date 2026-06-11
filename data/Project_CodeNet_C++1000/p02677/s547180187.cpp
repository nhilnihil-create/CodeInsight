#include <bits/stdc++.h>
#define M_PI 3.14159265358979323846
using namespace std;


int main()
{
    int h1,h2,h,w;
    cin>>h1>>h2>>h>>w;
    long double angle=abs(((long double)h/(long double)12)*(long double)360+((long double)w/(long double)60)*(long double)30-((long double)w/(long double)60)*(long double)360);
    if(angle>(long double)180)
        angle=(long double)360-angle;
    long double ans=sqrt(((long double)(h1*h1+h2*h2)-(long double)(2*h1*h2)*cos(angle*M_PI/(long double)180)));
    cout<<setprecision(10)<<fixed<<ans<<'\n';
    return 0;

}
/***
5 4 1
1000000000 1000000000 1000000000 1000000000 1000000000
1000000000 1000000000 1000000000 1000000000
3 4 730
60 90 120
80 150 80 150
*/
