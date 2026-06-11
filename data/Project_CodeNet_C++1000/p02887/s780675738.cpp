#include<iostream>
using namespace std;
int main()
{
   int n,p=1;
   cin>>n;
   char s[n],c;
   for(int i=0;i<n;i++)
   {
       cin>>s[i];
   }
   c=s[0];

   for(int i=1;i<n;i++)
   {
       if(s[i]==c)
       {
           continue;
       }
       else
       {
         p++;
         c=s[i];
       }
   }
   cout<<p<<endl;
    return 0;
}
