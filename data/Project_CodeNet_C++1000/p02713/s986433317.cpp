#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll; //10^19 < 9223372036854775807
typedef unsigned long long ull; //10^20 < 18446744073709551615

int gcd(int a, int b){
   if (a%b == 0){
       return(b);
   }
   else{
       return(gcd(b, a%b));
   }
}
int main(){
  int k; cin>>k;
  int ans=0;
  
  for(int a=1; a<=k; a++){
    for(int b=1; b<=k; b++){
      for(int c=1; c<=k; c++){
        ans+=gcd(c, gcd(a,b));
      }
    }
  }
  cout << ans;
}