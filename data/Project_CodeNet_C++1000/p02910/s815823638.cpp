#include <bits/stdc++.h>
using namespace std;
int main() 
{
int i,m;
string n;

 cin>>n;
 m=0;
 for(i=0;i<n.size();i++)
 {
     if(i%2==0)
     {
         if(n[i]=='R'||n[i]=='U'||n[i]=='D')
       {
         m++;
       }
     
     }
     else
     {
        if(n[i]=='L'||n[i]=='U'||n[i]=='D')
       {
         m++;
       } 
     }
 }
 if(m==n.size())
 {
     cout<<"Yes"<<endl;
 }
 else
 {
     cout<<"No"<<endl;
 }
}
