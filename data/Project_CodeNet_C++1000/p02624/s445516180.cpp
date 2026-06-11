#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define pb push_back
#define mk make_pair



int main(){
   ll n;
   cin>>n;
   ll ans=0;
   vector<ll> count(10000001,2);
   count[1]=1;
  // vector<ll> prime(10000001,false);
   for(ll i=2;i<=10000000;i++){
       //if(prime[i]==false){
           for(ll j=2*i;j<=10000000;j+=i){
              // prime[j]=true;
               count[j]+=1;
           }
       //}
   }
  for(ll i=1;i<=n;i++){
      ans+=count[i]*i;
  }
   cout<<ans<<endl;
}
