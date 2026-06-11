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
  int n,d;cin>>n>>d;
  vector<vector<int>> x(n,vector<int>(d));
  rep(i,n){
      rep(j,d)cin>>x[i][j];
  }
  map<int,int> sq;
  int res=0;
  rep(i,1000)sq[i*i]+=1;
  rep(i,n){
      for(int j=i+1;j<n;++j){
          lint buf=0;
          rep(k,d){
              buf+=(x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
          }
          if(sq[buf]==1)++res;
      }
  }
  cout<<res<<"\n";
  return 0;
}