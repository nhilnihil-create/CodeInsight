#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
   ll a,b,c,k,cnt=0;
   cin>>a>>b>>c>>k;
   if(k<=(a+b)){

   cout<<min(a,k)<<endl;

   }
   else{
    cout<<2*a-k+b<<endl;
   }
   return 0;
}
