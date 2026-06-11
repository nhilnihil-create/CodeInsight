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
   cin>>n;
   ll arr[n+5];

   for(ll i=0;i<n;i++){
    cin>>arr[i];
   }
   ll flag=0;
   for(ll i=0;i<n;i++){
    if(arr[i]%2==0){
            if(arr[i]%3==0){
                continue;
            }
            else if(arr[i]%5==0){
                continue;
            }
            else{
        flag=1;
        break;
            }   
    }
   }
   if(flag){
    cout<<"DENIED"<<endl;
   }
   else
    cout<<"APPROVED"<<endl;
}
