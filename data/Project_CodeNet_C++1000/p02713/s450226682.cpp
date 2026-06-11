#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int GCD2(int n,int m){
  if(m==0){
    return n;
  }
  return GCD2(m,n%m);
}

int GCD3(int n,int m,int l){
  return GCD2(GCD2(n,m),l);
}

int main(){
  int K;
  cin >> K;
  ll ans=0;
  for(int i=1;i<=K;i++){
    for(int j=1;j<=K;j++){
      for(int k=1;k<=K;k++){
        ans+=GCD3(i,j,k);
      }
    }
  }
  cout << ans << endl;
}