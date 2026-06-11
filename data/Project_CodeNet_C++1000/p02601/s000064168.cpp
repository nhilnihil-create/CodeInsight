#include<iostream>
using namespace std;
#define FIO \
    freopen("input.txt","r",stdin); \
    freopen("output.txt","w",stdout);
int main()
{
   //FIO;
   int a,b,c; cin>>a>>b>>c;
   int k; cin>>k;
   while(k)
   {
       if( a < b)
         break;
        b *= 2;
        k--;
   }
  // cout<<k<<endl;
   while(k--)
   {
      if(b < c)
        break;
       c *= 2;
   }
  // cout<<a<<' '<<b<<' '<<c<<endl;
   if(a < b && b < c)
     cout<<"Yes\n";
   else
     cout<<"No\n";
   
}