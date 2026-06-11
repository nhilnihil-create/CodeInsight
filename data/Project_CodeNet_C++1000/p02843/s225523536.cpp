#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;

//購入可能な個数n個の最大円... 5n;


int main(){
  int x;
  cin >>x;
  int n,zeni;
  int ans=0;
  
  n=x/100;
  while(n>0){
  	zeni=x-100*n;//小銭金額
    if(zeni<=5*n){
      ans=1;
      break;
    }
    
  
  n--;
  }
  if(n==0){
    ans=0;
  }
  
  cout<<ans<<endl;
  
}
