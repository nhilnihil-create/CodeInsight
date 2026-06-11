#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define repone(i,n) for(int i=1;i<(int)(n);++i)
#define repo(i,o,n) for(int i=o;i<(int)(n);++i)
#define Rep(j,n) for(int j=0;j<(int)(n);++j)
#define Repo(j,o,n) for(int j=o;j<(int)(n);++j)
#define Repone(j,n) for(int j=1;j<(int)(n);++j)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define int long long
#define pb(a) push_back(a)
#define eraser(v,i) (v).erase(v.begin()+(i))
#define pbpair(a,b) push_back(make_pair(a,b))
#define Little 1
const long long INF = 1LL<<60;
#define pairint pair<int,int>
signed main(){
  int N=0,M=0,X=0,ans=INF;
  std::cin >> N>>M>>X;
  int v[N][M+1]={};
  int vv[M]={};
  rep(i,N)Rep(j,M+1)std::cin >> v[i][j];
  bool exist = false,a=true;
  for(int bit = 0;bit < (1<<N);++bit){
    int sum = 0;
    for(int i=0;i<N;++i){
      if(bit &(1<<i)){
        sum+=v[i][0];
        rep(j,M)vv[j]+=v[i][j+1];
      }
    }
    rep(i,M){
      if(vv[i]<X)a=false;
      vv[i]=0;
    }
    if(a){
      if(sum<ans)ans=sum;
      exist=true;
    }
    a=true;
    sum=0;
  }
  if(exist)std::cout << ans << '\n';
  else std::cout << -1 << '\n';
}
