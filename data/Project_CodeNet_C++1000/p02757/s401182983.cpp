#include<bits/stdc++.h>
using namespace std; 
int main() 
{long long n,p;cin>>n>>p;
 string s;cin>>s;
 long long cur=1,mod=0,ans=0;
 map<long long,long long>f;
 f[0]++;
 if(p==2 || p==5){
   for(long long i=n-1;i>=0;i--)
 {
 if((s[i]-'0')%p==0)ans+=(i+1);
 }
                 }
 else{
 for(long long i=n-1;i>=0;i--)
 {
   mod=(mod+cur*(s[i]-'0'))%p;
   cur=(cur*10)%p;
   ans+=f[mod];
   f[mod]++;
 }
 }
 cout<<ans;
 return 0; 
}
