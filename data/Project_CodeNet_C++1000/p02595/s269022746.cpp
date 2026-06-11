#include <iostream>
#include <vector> 
#include<math.h>
#include <algorithm>
using namespace std; 
int main()
{ 
double a,b,c,d,e,f,i;
cin>>a>>b;
double g=0;
for(i=0;i<a;i++)
{

cin>>c>>d;
e=sqrt(c*c+d*d);


if(e<=b)g++;
}
cout<<g;
}