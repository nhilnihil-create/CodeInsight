#include <iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    double n=0,a=0,b=0,c=0,d=0,i=0,j=0;
    cin >> a >> b >> c >> d;
    i=(sqrt(((c-a)*(c-a))+((d-b)*(d-b))));
   // printf("%.5f\n",i);
    cout <<setprecision(14)<<  i <<endl;

}