#include <iostream>
using namespace std;
int main()
{
   int n, d;
   cin>>n;
   d=n%2;
   if (d==0)
   {
       cout<<n/2;
   }
   else 
   {
       cout<<(n/2)+ 1;
   }
    
    return 0;
}