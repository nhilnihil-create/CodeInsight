#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll power(ll p,ll n){
   ll result=1;
   while(n!=0){
   if(n%2==0){
    n/=2;
    p*=p;
   }
   else{
    n--;
    result=result*p;
   }
   }
    return result;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   ll n,t,a,b,c,d;
   ll mod =1e9+7;
   string s1,s2;
   stack<ll>stck1;
   stack<ll>stck2;

   set<ll>st;
   map<string,ll>mp;
   cin>>n;
   cin>>s1;
   ll cnt=0;
   for(ll i=0;i<s1.length()-2;i++){
    if(s1[i]=='A' && s1[i+1]=='B' && s1[i+2]=='C'){
        cnt++;
    }
   }
   cout<<cnt<<endl;
}
