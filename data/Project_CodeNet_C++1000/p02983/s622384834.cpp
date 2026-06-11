#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
using ll = long long;
using lint = long long;
typedef pair<int,int> P;
const lint inf=1e18+7;
const int MOD=1000000007;
signed main(){
  lint l,r;cin>>l>>r;
  if(r-l>=2019){
      cout<<0<<"\n";
      return 0;
  }
  l%=2019;r%=2019;
  lint res=inf;
  if(r<=l){
      cout<<0<<"\n";
      return 0;
  }
  for(int i=l;i<=r;++i){
      for(int j=i+1;j<=r;++j){
          res=min(res,(i*j)%2019);
      }
  }
  cout<<res<<"\n";
  return 0;
}