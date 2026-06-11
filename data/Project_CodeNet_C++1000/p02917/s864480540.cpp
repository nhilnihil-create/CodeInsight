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
  int n;cin>>n;
  vector<int> b(n);
  rep1(i,n-1)cin>>b[i];
  int res=b[1]+b[n-1];
  rep1(i,n-2){
      res+=min(b[i],b[i+1]);
  }
  cout<<res<<"\n";
  return 0;
}