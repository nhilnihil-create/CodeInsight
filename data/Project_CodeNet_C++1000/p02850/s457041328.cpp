#include<queue>
#include<stack>
#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
#include<functional>
#include<deque>
#include<list>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  vector<vector<int> > g(100010);
  int n,i,a[100010],b[100010];
  cin >> n;
  for(i=0;i<n-1;i++){
    cin >> a[i] >> b[i];
    a[i]--,b[i]--;
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }
  map<P,int> mp;
  vector<int> seen(100010,0);
  queue<int> que;
  que.push(0);
  vector<int> c(100010,-1);
  int ans=0;
  while(!que.empty()){
    int v=que.front();
    que.pop();
    if(seen[v]==1){
      continue;
    }
    seen[v]=1;
    int color=0;
    for(i=0;i<g[v].size();i++){
      if(seen[g[v][i]]==1){
        continue;
      }
      if(c[v]==color){
        color++;
      }
      c[g[v][i]]=color;
      mp[P(v,g[v][i])]=color;
      mp[P(g[v][i],v)]=color;
      color++;
      que.push(g[v][i]);
      if(ans<color){
        ans=color;
      }
    }
  }
  cout << ans << endl;
  for(i=0;i<n-1;i++){
    cout << mp[P(a[i],b[i])]+1 << endl;
  }
  return 0;
}