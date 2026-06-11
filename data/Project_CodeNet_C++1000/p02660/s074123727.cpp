#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
#define ll long long int

int main(){
   ll n;
   cin>>n;

   int cnt=0;
   for(int i=2; ; i++){
      for(ll z=i; n%z==0; z*=i){
         n/=z;
         cnt++;
      }
      while(n%i==0) n/=i;
      if (n==1) break;
      if (i==1000000){
         if(n>1000000) cnt++;
         break;
      }
   }

   cout << cnt << endl;
   return 0;
}
