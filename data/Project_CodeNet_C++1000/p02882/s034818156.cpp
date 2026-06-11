#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PI 3.14159265
int main()
{
   double a , b, x;
    cin>>a>>b>>x;
    double ans ;

    if( a*a*b <= 2*x)
      ans =double (atan( 2*(a*a*b - x) / (a*a*a) ) );
    else
    {
        ans = double( atan(  b*b*a / ( 2*x)    )    );

    }
   ans = ans *180/PI;
   printf("%.15lf" , ans);
}