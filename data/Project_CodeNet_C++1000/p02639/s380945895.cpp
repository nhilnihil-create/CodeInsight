#include<iostream>
using namespace std;
int main()
{
    int a[5];
 
  for(int i=1;i<=5;i++)
   { 
       cin>>a[i];
   }
   for(int i=1;i<=5;i++)
   {
      if(a[i]==0)
      {
          cout<<i<<endl;
      }
   }
   return 0;
}