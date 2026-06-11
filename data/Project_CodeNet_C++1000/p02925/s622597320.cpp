#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,n) for(int i=m;i<n;i++)

int main() {
  int n;
  cin>>n;
  int a[n][n-1];
  rep(i,0,n){
    rep(j,0,n-1){
      int b;
      cin>>b;
      a[i][j]=b-1;
    }
  }
  int cur[n];
  rep(i,0,n) cur[i]=0;
  queue<int> q;
  rep(i,0,n) q.push(i);
  int p=n;
  int ans=0;
  while(p<n*n){
    int k=q.size();
    if(k==0) break;
    set<int> f;
    rep(i,0,k){
      int c=q.front();
      q.pop();
      if(!f.count(c)){
        int d=a[c][cur[c]];
        if(a[d][cur[d]]==c){
          p+=2;
          f.insert(d);
          if(cur[c]!=n-2){
            q.push(c);
          }
          if(cur[d]!=n-2){
            q.push(d);
          }
        }
      }
    }
    ans++;
    queue<int> r=q;
    while(r.size()){
      int e=r.front();
      r.pop();
      cur[e]++;
    }
  }
  if(p==n*n) cout<<ans<<endl;
  else cout<<-1<<endl;
}
