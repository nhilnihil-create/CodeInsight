#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<cassert>
#include<numeric>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
const int INF = 1001001001;
const long long LINF = 1001002003004005006ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int,int> P;

const int MAXN = 1005;
const int MAXV = MAXN*(MAXN-1)/2;

int id[MAXN][MAXN];
int calc_v(int a,int b){
  if(a>b)swap(a,b);
  return id[a][b];
}

vector<int> to[MAXV];
vector<int> d(MAXV,-1);
vector<int> calced(MAXV,-1);
bool dag = 1;

int dfs(int v){
  if(d[v]!=-1)return d[v];
  d[v]=0;
  calced[v]=0;
  for(int u:to[v]){
    if(calced[u]==0){
      dag = 0;
      continue;
    }
    chmax(d[v],dfs(u)+1);
  }
  calced[v]=1;
  return d[v];
}

int main(){
  int n;
  cin >> n;
  vector<vector<int>> a(n,vector<int>(n-1));
  rep(i,n)rep(j,n-1){
    int t;
    cin >> t;
    t--;
    a[i][j]=t;
  }
  int v=0;
  rep(i,n)rep(j,n){
    if(i<j){
      id[i][j]=v;
      v++;
    }
  }
  rep(i,n)rep(j,n-2){
    int from = calc_v(i,a[i][j]);
    int tov = calc_v(i,a[i][j+1]);
    to[from].push_back(tov);
  }
  int ans = 0;
  rep(i,v){
    chmax(ans,dfs(i));
  }
  if(dag)cout << ans + 1 << endl;
  else cout << -1 << endl;
}