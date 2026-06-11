#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

int ans;
vector<int> a,b,c,d;
int n,m,q;

void cal(vector<int> &A){
  int now=0;
  rep(i,q){
    if(A[b[i]]-A[a[i]]==c[i]) now+=d[i];
  }
  ans=max(ans,now);
}

void dfs(int i, vector<int> A){
  if(A.size()==n+1){
    cal(A); return;
  }
  for(int j=i; j<=m; j++){
    A.push_back(j);
    dfs(j,A);
    A.pop_back();
  }
}

int main(){
  cin>>n>>m>>q;
  a.resize(q);
  b.resize(q);
  c.resize(q);
  d.resize(q);
  rep(i,q) cin>>a[i]>>b[i]>>c[i]>>d[i];
  ans=0;
  vector<int> A;
  A.push_back(1);
  dfs(1,A);
  cout<<ans<<endl;
}

