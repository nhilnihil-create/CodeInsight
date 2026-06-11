


#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

const int MAXN = 1005;

int dp[500005];
vector<int> to[5000005];
bool visited[500005];
bool calc[500005];
int id[1005][1005];

int dfs(int v){
//  cout<<'t';
  if (visited[v]) {
    if (!calc[v])return -1;
    return dp[v];
  }
//  cout<<'n';
  visited[v]=true;
//  cout<<v<<'v'<<endl;
  for(int t:to[v]){
//    cout<<t<<'t'<<endl;

  //  cout<<dp[v]<<endl;
    int res=dfs(t);
    if (res==-1) return -1;
    dp[v]=max(dp[v],res+1);
  }
  calc[v]=true;
  return dp[v];
}

int main() {
  rep(i,500000)dp[i]=1;
  rep(i,500000)visited[i]=false;
  rep(i,500000)calc[i]=false;
  int n;
  cin>>n;
  int a[n][n-1];
  rep(i,n){
    rep(j,n-1){
      cin>>a[i][j];
      a[i][j]--;
    }
  }
int V=0;
rep(i,n-1){
  for(int j=i+1;j<n;j++){
    id[i][j]=V;
//    cout<<V<<'v'<<i<<'i'<<j<<'j'<<endl;
    V++;
  }
}

rep(i,n)rep(j,n-1){
  if (i<a[i][j])a[i][j]=id[i][a[i][j]];
  else a[i][j]=id[a[i][j]][i];
}
rep(i,n){
  rep(j,n-2){
  //  cout<<i<<' '<<j<<endl;

    to[a[i][j]].push_back(a[i][j+1]);
  //  cout<<a[i][j]<<a[i][j+1]<<i<<'i'<<j<<'j'<<endl;
  }
}

//cout<<to[0][1]<<'c'<<endl;
int ans=0;
rep(i,V){
  if (dfs(i)==-1){
    cout<<-1;
    return 0;
  }
  ans=max(ans,dfs(i));
//  cout<<dfs(V);}
}
cout<<ans;
}
