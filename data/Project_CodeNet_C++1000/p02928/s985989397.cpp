#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int mod=1000000007;
  long n,k;
  cin >> n>>k;
  vector<int>a(n);
  rep(i,n){
    cin>>a.at(i);
  }
  long ans=0;
  long u=0;
  rep(i,n){
    rep2(j,i+1,n){
      if(a.at(i)>a.at(j)){
        ans++;
      }
      if(a.at(i)<a.at(j)){
        u++;
      }
    }
  }
  long an=k*(k+1)/2%mod;
  long bn=k*(k-1)/2%mod;
  u=u*bn%mod;
  ans=ans*an%mod;
  ans=(ans+u)%mod;
  cout<<ans<<endl;
}