#include<bits/stdc++.h>
using namespace std;
int main()
{int n;
 cin>>n;
 int c=0;
 while(n>0)
 {
   if(n%10==7)
   {
     c++;
     break;
   }
   
   n=n/10;
 }
 if(c>0)
   cout<<"Yes";
 else
   cout<<"No";
 
 return 0;
}