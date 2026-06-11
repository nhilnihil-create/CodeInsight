#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

   double n;
   cin>>n;
   double x=(n/1.08);
   double k=ceil(x);
   double kk=k*1.08;
   double mm=floor(kk);
   if(mm==n)
   {
       cout<<k<<endl;
   }
   else
   {
       cout<<":("<<endl;
   }

}

