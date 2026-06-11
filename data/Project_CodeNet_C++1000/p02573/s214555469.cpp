#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<ll, ll> P;

struct edge {int to, cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

ll GCD(ll a, ll b){
  if(b==0) return a;
  else return GCD(b, a%b);
}

ll LCM(ll a, ll b){
  if(a<b) swap(a,b);
  return a/GCD(a,b)*b;
}

int par[200005];
int rank_[200005];
void init(int n){
  for(int i=0; i<n; i++){
    par[i] = i;
    rank_[i] = 1;
  }
}

int find(int x){
  if(x==par[x]){
    return x;
  }else{
    return par[x] = find(par[x]);
  }
}

void unite(int x, int y){
  x = find(x);
  y = find(y);
  if(x==y) return;
  if(rank_[x]<rank_[y]){
    par[x]=y;
    rank_[y] += rank_[x];
    rank_[x] = rank_[y];
  }else{
    par[y]=x;
    rank_[x] += rank_[y];
    rank_[y] = rank_[x];
  }
}

int main(){
  int n, m;
  cin >> n >> m;
  init(n);
  for(int i=0; i<m; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    unite(a, b);
  }
  int ans = 0;
  for(int i=0; i<n; i++){
    ans = max(ans, rank_[i]);
  }
  cout << ans << endl;
  return 0;
}
