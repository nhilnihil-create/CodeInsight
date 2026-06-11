#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
int main(){
  int n;
  cin>>n;
  long mod=1000000007;
  vector<long>a(n);
  rep(i,n){
    cin>>a.at(i);
  }
  vector<long>c(60);
  rep(i,60){
    rep(j,n){
      c.at(i)+=a.at(j)%2;
      a.at(j)/=2;
    }
  }
  long ans=0;
  rep(i,60){
    ans=(ans+(long)pow(2,i)%mod*(n-c.at(i))%mod*c.at(i))%mod;
  }  
  cout<<ans<<endl;  
}