#include<iostream>
using namespace std;
int main()
{

   long long int x,n,r,s,res;
   cin>>n;
   x=n/500;
   r=n%500;
   s=r/5;
   res=x*1000+s*5;
   cout<<res<<endl;


 return 0;
}
