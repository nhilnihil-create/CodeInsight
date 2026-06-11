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

   ll n,t,a,b,c;
   ll mod =1e9+7;
   string s1,s2;
   cin>>s1>>s2;
   ll cnt=0;
   for(ll i=0;i<s1.length();i++){
    if(s1[i]!=s2[i]){
        cnt++;
    }
   }
   cout<<cnt<<endl;
}
