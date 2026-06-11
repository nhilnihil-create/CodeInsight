#include<bits/stdc++.h>
using namespace std;

int main()
{
   long long int i,j,x;
   cin>>x;
   for(i=-2000;i<=2000;i++)
   {
       for(j=-2000;j<=2000;j++)
       {
           if(pow(i,5)-pow(j,5)==x)
           {
               cout<<i<<" "<<j<<endl;
               return 0;
           }
       }
   }
    return 0;
}
