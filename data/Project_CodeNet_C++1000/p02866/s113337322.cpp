#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int mod=998244353;
  int n;
  cin >> n;
  int ma=0;
  vector<int>x(n),y(n);
  rep(i,n){
    cin>>x.at(i);
    ma=max(ma,x.at(i));
    y.at(x.at(i))++;
  }
  if(x.at(0)!=0||y.at(0)>1){
    cout<<0<<endl;
  }
  else{
    long ans=1;
    rep2(i,1,ma+1){
      int a=y.at(i-1);
      int b=y.at(i);
      long c=1;
      while(b--){
        c=c*a%mod;
      }
      ans=ans*c%mod;
    }
    cout<<ans<<endl;
  }
  
}



