#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
  ll t;
 // cin>>t;
 // while(t--){
  ll a,b=0,c=0,d=0,e=0;
  string s;
  cin>>s;
  b=s.length();
  for(ll i=0;i<b;i++){d=d+(s[i]-'0');}
   
   if(d%9==0){cout<<"Yes";}
   else{cout<<"No";}
 // }
}