#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main() {
  string s;
  cin>>s;
  int n=s.size();
  ll dp0[n+1];
  ll dp1[n+1];
  dp0[0]=0;
  dp1[0]=1;
  rep(i,0,n){
    if(s[i]=='0'){
      dp0[i+1]=dp0[i]*3%mod;
      dp1[i+1]=dp1[i]%mod;
    }
    else{
      dp0[i+1]=(dp0[i]*3%mod+dp1[i])%mod;
      dp1[i+1]=dp1[i]*2%mod;
    }
  }
  cout<<(dp0[n]+dp1[n])%mod<<endl;
}
