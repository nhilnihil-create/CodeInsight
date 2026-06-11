
#include<bits/stdc++.h>
using namespace std;
int main(){
  int res=0;
  int K;cin>>K;
  for(int i=1;i<=K;i++){
    for(int j=1;j<=K;j++){
      for(int l=1;l<=K;l++){
        int tmp=__gcd(i,j);
        res+=__gcd(tmp,l);
      }
    }
  }
  cout<<res<<endl;
}