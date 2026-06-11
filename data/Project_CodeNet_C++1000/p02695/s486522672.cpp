#include<bits/stdc++.h>
using namespace std;
int64_t n,m,q;
vector<int64_t> a;
vector<int64_t> b;
vector<int64_t> c;
vector<int64_t> d;
int64_t ans=0;
void dfs(vector<int64_t>Q){
  if(Q.size()==n){
    int64_t score=0;
    for(int64_t i=0;i<q;i++){
      if(Q[b[i]-1]-Q[a[i]-1]==c[i])score+=d[i];
    }
    ans=max(ans,score);
    return;
  }
  Q.push_back(Q.back());
  while(Q.back()<=m){
    dfs(Q);
    Q.back()++;
  }
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m >> q;
  a=b=c=d=vector<int64_t>(q);
  for(int64_t i=0;i<q;i++)cin >> a[i] >> b[i] >> c[i] >> d[i];
  dfs({1});
  cout << ans << endl;
}
