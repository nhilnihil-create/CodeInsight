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

int color[100005];
vector<int> G[100005];
int deg[100005];
map<P, int> mp;

void dfs(int v,int p, int pcolor){
  int num=1;
  for(int nv: G[v]){
    if(nv==p)continue;
    if(num==pcolor)num++;
    color[mp[P(v, nv)]]=num;
    dfs(nv, v, num);
    num++;
  }
}



int main(){
  int n;
  cin >> n;
  rep(i, n-1){
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
    mp[P(a, b)]=i;
    mp[P(b, a)]=i;
    deg[a]++;deg[b]++;
  }
  dfs(0, -1, -1);
  int maxdeg=0;
  rep(i, n-1){
    maxdeg=max(maxdeg, color[i]);
  }
  cout << maxdeg << endl;
  rep(i, n-1){
    cout << color[i] << endl;
  }
  return 0;
}
