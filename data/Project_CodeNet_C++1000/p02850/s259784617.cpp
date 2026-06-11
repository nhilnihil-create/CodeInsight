#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000

int MOD=1000000007;

int modpow(int a,int x){
  if(a<0)a+=MOD;
  int ans=1;
  while(x>0){
    if(x&1) ans=ans*a%MOD;
      a=a*a%MOD;
      x>>=1;
  }
  return ans;
}
int gyaku(int n){
    return modpow(n,MOD-2);
}
signed main() {
int n;
cin>>n;
vector<vector<int>>g(n,vector<int>(0));
vector<pair<int,int>>v(n-1);
rep(i,n-1){
  int a,b;
  cin>>a>>b;
  a--;b--;
  if(a>b)swap(a,b);
  v[i].first=a;
  v[i].second=b;
  g[a].push_back(b);
  g[b].push_back(a);
}

int ans=0;
rep(i,n){
  int k=g[i].size();
  ans=max(k,ans);
}

map<pair<int,int>,int>color;
vector<bool>visited(n);

queue<pair<int,int>>q;

visited[0]=true;
rep(i,g[0].size()){
  int t=g[0][i];
  visited[t]=true;
  pair<int,int>p(t,i+1);
  q.push(p);
  pair<int,int>p2(0,t);
  color[p2]=(i+1);
}

while(!q.empty()){
  pair<int,int>t=q.front();
  q.pop();
  int a=t.first;
  int b=t.second;
  int cnt=0;
  rep(i,g[a].size()){
    
    if(!visited[g[a][i]]){
      visited[g[a][i]]=true;
      int c=(b+cnt)%ans+1;
      pair<int,int>p(g[a][i],c);
      int x=min(a,g[a][i]),y=max(a,g[a][i]);
      pair<int,int>p2(x,y);
      color[p2]=c;
      q.push(p);
      cnt++;
    }
  }
}
cout<<ans<<endl;
rep(i,n-1){
  auto p=v[i];
  cout<<color[p]<<endl;
}
}
