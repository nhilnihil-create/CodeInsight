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
using ll = long long;
using lint = long long;
typedef pair<int,int> P;
const lint inf=1e18+7;
const int MOD=1000000007;
signed main(){
  int n;cin>>n;
  string s;cin>>s;
  lint res=1;
  lint l=0;lint r=0;
  vector<int> memo(2*n,0);
  rep(i,2*n){
      if((l-r+(int)(s[i]=='W'))%2==1){
          ++r;
          memo[i]=0;
      }
      else{
          ++l;
          memo[i]=1;
      }
      if(l<r)res=0;
  }
  lint l_num=0;
  rep(i,2*n){
      //cout<<memo[i];
      if(memo[i]==1)++l_num;
      else{
          res*=l_num;res%=MOD;
          --l_num;
      }
  }
  if(l_num!=0)res=0;
  rep1(i,n){
      res*=i;res%=MOD;
  }
  cout<<res<<"\n";
  return 0;
}