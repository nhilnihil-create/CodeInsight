#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
   int n,d;
   cin>>n>>d;
   double x[n];
   double y[n];
   for(int i=0;i<n;i++)
   {
       cin>>x[i]>>y[i];
   }
   int sum=0;
   for(int i=0;i<n;i++)
   {
       double a=(x[i]*x[i])+(y[i]*y[i]);
       a=sqrt(a);

       if(a<=d) sum++;
   }
   cout<<sum<<endl;

   return 0;
}
