#include<iostream>
using namespace std;
int main()
{
   int r,t;
   cin>>r>>t;
   if(r>9 || t>9)
   {
       cout<<"-1"<<endl;
   }
   else
   cout<<r*t<<endl;
   return 0;
}
