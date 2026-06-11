#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int id[1005][1005];
bool visited[500005];
bool calculated[500005];
vector<int> d(500005, 1);
vector<int> to[500005];

int dfs(int v){
  if(visited[v]){
    if(!calculated[v])return -1;
    return d[v];
  }
  visited[v]=true;
  for(int nv:to[v]){
    int res=dfs(nv);
    if(res==-1)return -1;
    d[v]=max(d[v], res+1);
  }
  calculated[v]=true;
  return d[v];
}

int main(){
  int n;
  cin >> n;
  int idnum=0;
  rep(i, n){
    for(int j=i+1; j<n; j++){
      id[i][j]=idnum;
      idnum++;
    }
  }
  rep(i,n){
    int a0;
    cin >>a0;
    a0--;
    rep(j, n-2){
      int a;
      cin >> a;
      a--;
      to[id[min(i, a0)][max(i, a0)]].push_back(id[min(i, a)][max(i, a)]);
      a0=a;
    }
  }
  int ans=0;
  rep(i, n*(n-1)/2){
    int di=dfs(i);
    if(di==-1){
      cout << "-1" << endl;
      return 0;
    }
    ans=max(ans, di);
  }
  cout << ans << endl;
  return 0;
}
