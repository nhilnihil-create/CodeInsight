#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
typedef long long ll;
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)


int N,M;
int par[200010];
int rnk[200010];

void init(int n){
  for(int i=0;i<n;i++){
    par[i] = i;
    rnk[i] = 0;
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
  
  if(rnk[nx]<rnk[ny]){
    par[nx] = ny;
  }else{
    par[ny] = nx;
    if(rnk[nx]==rnk[ny]) rnk[nx]++;
  }
}

bool same(int x,int y){
  return find(x)==find(y);
}

int main(){
  cin >> N >> M;
  init(N);
  for(int i=0;i<M;i++){
    int x,y;
    cin >> x >> y;
    unite(x,y);
  }
  map<int,int> mp;
  int ans = 0;
  for(int i=0;i<N;i++){
    mp[find(i)]++;
    ans = max(ans,mp[find(i)]);
  }
  cout << ans << endl;
 
}