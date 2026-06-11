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
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
using lint=long long;
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
signed main(){
  int n;cin>>n;
  vector<int> v(n);
  rep(i,n)cin>>v[i];
  sort(v.begin(),v.end());
  double res=v[0];
  rep1(i,n-1){
      res=(res+(double)v[i])/2.0;
  }
  cout<<res<<"\n";
  
  return 0;
}