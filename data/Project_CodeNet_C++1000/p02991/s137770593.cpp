#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main() {
  int n,m;
  cin>>n>>m;
  vector<int> a[n];
  rep(i,0,m){
    int f,t;
    cin>>f>>t;
    a[f-1].push_back(t-1);
  }
  int s,t;
  cin>>s>>t;
  int d[n];
  rep(i,0,n){
    d[i]=-1;
  }
  bool used[n][3];
  rep(i,0,n){
    rep(j,0,3){
      used[i][j]=false;
    }
  }
  queue<int> q;
  q.push(s-1);
  d[s-1]=0;
  used[s-1][0]=true;
  int cur=0;
  while(q.size()){
    int c=q.size();
    rep(i,0,c){
      int p=q.front();
      q.pop();
      rep(i,0,a[p].size()){
        if(!used[a[p][i]][(cur+1)%3]){
          q.push(a[p][i]);
          used[a[p][i]][(cur+1)%3]=true;
          if((cur+1)%3==0){
            d[a[p][i]]=(cur+1)/3;
          }
        }
      }
    }
    cur++;
  }
  cout<<d[t-1]<<endl;
}
