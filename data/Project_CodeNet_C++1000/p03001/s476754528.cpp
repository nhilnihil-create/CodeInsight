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
  int w,h;cin>>w>>h;
  int x,y;cin>>x>>y;
  int kazu=0;
  if(x*2==w&&y*2==h)kazu=1;
  double res=h*w/2.0;
  printf("%.12lf ",res);
  cout<<kazu<<"\n";
  return 0;
}