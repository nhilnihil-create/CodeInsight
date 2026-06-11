#include<bits/stdc++.h>
using namespace std;

int main()

{
   long long a=0,b,c,d,e,f,g,h,i,j,k,l,m,n,t;

   cin>>n;

   long long ar[n];

   for(i=1;i<=n;i++)
   {
       cin>>ar[i];

       if(ar[i]!=i) a++;
   }

   if(a<=2) cout<<"YES"<<endl;

   else if(a>2) cout<<"NO"<<endl;
}
