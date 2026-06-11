#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   ll n;
   cin>>n;

   if(n%2==1){
      cout<< 0 <<endl;
   }
   else{
      ll cnt=0;
      for(ll k=5; k<=n; k*=5){
         ll k2=k*2;
         cnt+= n/k2;
      }
      cout<<cnt<<endl;
   }
   return 0;
}
