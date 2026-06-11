#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int DP[1005][(1<<12)];

int main() {
  int N, M;
  cin>>N>>M;
  for(int i=0;i<M;++i) {
    for(int j=0;j<(1<<N);++j) {
      DP[i][j] = inf;
    }
  }
  int a[M], b[M];
  vector<vector<int> > c(M);
  int tmp;
  for(int i=0;i<M;++i) {
    cin>>a[i]>>b[i];
    for(int j=0;j<b[i];++j) {
      cin>>tmp;
      tmp--;
      c[i].push_back(tmp);
    }
  }
  tmp = 0;
  for(int i=0;i<c[0].size();++i) {
    tmp += (1<<c[0][i]);
  }
  DP[0][0] = 0;
  DP[0][tmp] = a[0];
  for(int i=0;i<M-1;++i) {
    for(int j=0;j<(1<<N);++j) {
      if(DP[i][j]<inf) {
        DP[i+1][j] = min(DP[i+1][j], DP[i][j]);
        tmp = j;
        for(int k=0;k<c[i+1].size();++k) {
          if((tmp&(1<<c[i+1][k]))==0) tmp += (1<<c[i+1][k]);
        }
        DP[i+1][tmp] = min(DP[i+1][tmp], DP[i][j]+a[i+1]);
      }
    }
  }
  if(DP[M-1][(1<<N)-1]==inf) cout<<-1<<endl;
  else cout<<DP[M-1][(1<<N)-1]<<endl;
}

