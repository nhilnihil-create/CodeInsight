#include <stdio.h>
#include <iostream>
using namespace std;
 
int main()
{
   int d,t,s;
   cin>>d>>t>>s;
   double res=(d*1.0)/s;
   if(res<=t)
   printf("Yes\n");
   else
   printf("No\n");
 
    return 0;
}