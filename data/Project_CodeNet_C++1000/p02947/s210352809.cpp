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
  map<string,int> memo;
  rep(i,n){
      string buf;cin>>buf;
      sort(buf.begin(),buf.end());
      memo[buf]+=1;
  }
  lint res=0;
  for(auto& val:memo){
      res+=val.second*(val.second-1)/2;
  }
  cout<<res<<"\n";
  return 0;
}