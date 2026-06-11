
                                 /*Bismillahir Rahmanir Rahim*/


#include<bits/stdc++.h>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define ll long long int
#define dd double
using namespace std;

int main()
{
   ll b,c,i,s=0,ans=0,r;
   string a;
   bool f=1;
   
   cin>>a;
   s=0;
   r=a.length()-1;
   while(s<r)
   {
     if(a[s]!=a[r])
     {
       f=0;
       break;
     }
     s++,r--;
   }
      if(f==0)
  {cout<<"No"<<endl;
   return 0;}
  else
   {
     s=0;
     r=(a.length()-1)/2;
     r--;
       while(s<r)
   {
     if(a[s]!=a[r])
     {
       f=0;
       break;
     }
      s++,r--;
   }
   if(f==0)
  {cout<<"No"<<endl;
   return 0;}
   s=(a.length()+3)/2;
   s--;
   r=a.length()-1;
      while(s<r)
   {
     if(a[s]!=a[r])
     {
       f=0;
       break;
     }
      s++,r--;
   }
      if(f==0)
  {cout<<"No"<<endl;
   return 0;}
   }
   cout<<"Yes"<<endl;


    

}
//Apna Time Aayega :)