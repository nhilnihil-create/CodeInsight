#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

int N,M;
int par[200010];
int rk[200010];
void init(int n){
  for(int i=1;i<=n;i++){
    par[i] = i;
    rk[i] = 1;
  }
}
int find(int x){
  if(par[x]==x) return x;
  return par[x] = find(par[x]);
}
void unite(int x,int y){
  int nx = find(x);
  int ny = find(y);
  if(nx==ny) return;
  par[nx] = ny;
  rk[ny] += rk[nx];
  rk[nx] = rk[ny];
}
int main(){
  cin >> N >> M;
  init(N);
  for(int i=0;i<M;i++){
    int x,y;
    cin >> x >> y;
    unite(x,y);
  }
  int ans = 0;
  for(int i=1;i<=N;i++){
    int num = par[i];
    ans = max(ans,rk[num]);
  }
  cout << ans << endl;
}
