#include <iostream>
using namespace std;
int kuch(int i)
{
    if(i==1)
    return 300000;
    if(i==2)
      return 200000;
    if(i==3)
      return 100000;
    
    return 0;
}
 
int main()
{
   int a,b;
  
   cin>>a>>b;
  
   int sum=0;
  
   if((a+b)==2)
   {
       sum = sum + kuch(a) + kuch(b) + 400000; 
   }
   else
   {
         sum = sum + kuch(a) + kuch(b);
   }
  
   cout<<sum<<endl;
   
}