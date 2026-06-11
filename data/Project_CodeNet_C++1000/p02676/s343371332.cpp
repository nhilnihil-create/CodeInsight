#include<bits/stdc++.h>
using namespace std;
int main()
{
     long long t,i,j,n,l,m,k,p;
    cin>>l;
   string s;
   cin>>s;
   n=s.length();
   if(n>l)
   {
       for(i=0;i<l;i++)
       cout<<s[i];
      cout<<"."<<"."<<".";   
   }
   else 
   cout<<s;
   
    
    
}