#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
   int cnt=1;
   int m=0;
   bool is=0;
   for(int i=0;i<3;i++)
   {
       if(i+1<3){
       if(s[i]=='R' && s[i+1]=='R')
       {
           is=1;
           cnt++;
       }
       }
   }
    if(s=="SSS"){
    cout<<0;
   }
   else {
    cout<<cnt;
   }
}
