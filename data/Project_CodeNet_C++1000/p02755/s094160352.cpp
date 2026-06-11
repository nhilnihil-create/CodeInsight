#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll; //10^19 < 9223372036854775807
typedef unsigned long long ull; //10^20 < 18446744073709551615


int main(){
  float a,b; cin>>a>>b;
  int price1,price2;
  int ans=-1;
  
  
  for(int i=10000; i>0; i--){
    price1=i*0.08;
    price2=i*0.1;
    if(a==price1){
      if(b==price2){
        ans=i;
        
      }
    }
  }
  cout<<ans;       
}