#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    string r=s;
    reverse(r.begin(),r.end());
    int n;
    cin>>n;
    int t,f;
    string ch;
    int flag=0;
    while(n--)
    {
       cin>>t;
       
       if(t==1)
       {
          flag=(flag^1);
       }
       if(t==2)
       {
          cin>>f;
          cin>>ch;
          if(f==1)
          {  if(flag==0)
             { 
              ch+=s;
            
              s=ch;
             }
           else
           {
              s+=ch;
             
           }}
          else
           { if(flag==0){
               s+=ch;
               }
            else
            {
                
              ch+=s;
            
           s=ch; 
            }}
       }
    }
    if(flag==1)
     reverse(s.begin(),s.end());
    cout<<s<<endl;
}