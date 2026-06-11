#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
int main()
{   int n,t,j=0;
      char c[6];
      for(int i=0;i<6;i++)cin>>c[i];
      
            if(c[2]==c[3]&& c[4]==c[5])cout<<"Yes";
            else cout<<"No";
 
   return 0;

}