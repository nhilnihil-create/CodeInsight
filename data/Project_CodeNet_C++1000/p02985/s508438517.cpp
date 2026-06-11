#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  long long n,k,ans=1,mod=1e9+7;
  cin >> n >> k;
  long long a[n-1],b[n-1];
  vector<long long> graph[n];
  for(int i=0;i<n-1;i++){
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    graph[a[i]].push_back(b[i]);
    graph[b[i]].push_back(a[i]);
  }
  for(int i=0;i<n;i++){
    if(graph[i].size()+1>(size_t)k){
      cout << "0\n";
      return 0;
    }
  }
  queue<long long> que;
  bool used[n];
  for(int i=0;i<n;i++){
    used[i]=false;
  }
  long long paint[n];
  paint[0]=k;
  used[0]=true;
  for(size_t i=0;i<graph[0].size();i++){
    if(!used[graph[0][i]]){
      que.push(graph[0][i]);
      used[graph[0][i]]=true;
      paint[graph[0][i]]=k-i-1;
    }
  }
  while(!que.empty()){
    long long now=que.front(),cnt=2;
    que.pop();
    for(size_t i=0;i<graph[now].size();i++){
      if(!used[graph[now][i]]){
        que.push(graph[now][i]);
        used[graph[now][i]]=true;
        paint[graph[now][i]]=k-cnt;
        cnt++;
      }
    }
  }
  for(int i=0;i<n;i++){
    ans*=paint[i];
    ans%=mod;
  }
  cout << ans << endl;
  return 0;
}