#include<bits/stdc++.h>
using namespace std;
#define pi 3.141592653589793238

int main()
{
    double a,b,x;
    double theta;
    cin >> a >> b >>x;
    if (x>a*a*b/2)
    {
        theta=atan(2/(a*a)*(a*b-x/a));
    }
    else
    {
         theta=atan(2*x/(b*b*a));
         theta=pi/2-theta;
    }
    cout <<fixed << setprecision(15)<<theta*180/pi << endl;
    return 0; 
    
}