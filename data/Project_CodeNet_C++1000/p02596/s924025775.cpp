#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
int main(){
   ll k,n;
   cin>>k;
   n=7%k;
   for(ll i=1;i<=10000000;i++){
      if(n==0){
         cout<<i;
         return 0;
      }
      n=(n*10LL+7LL)%k;
   }
   cout<<-1;
   return 0;
}