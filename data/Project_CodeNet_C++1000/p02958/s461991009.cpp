#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
   int a[100],b[100],n,c=0,v=0;
   cin>>n;
   for(int i=0;i<n;i++)
   {
     cin>>a[i];
   }
   copy(a,a+n,b);
   sort(b,b+n);
   for(int i=0;i<n;i++)
   {
       if(a[i]!=b[i])
       {
         c++;
         swap (a[i],b[i]);

       }
   }
   if(c<=2)
   {
      for(int i=0;i<n;i++)
      {
         if(a[i]<a[i+1])
         {
            v++;
         }
      }
      if(v==n)
      {
         cout<<"YES";
      }
      else
      {
         cout<<"NO";
      }
   }
   else
   {
      cout<<"NO";
   }

}


