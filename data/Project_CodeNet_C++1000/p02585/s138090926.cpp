#include <bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
template<typename T>
void chmax(T &a,T b){
  if(a<b)a=b;
}
int ans=-1e18,v[5555],c[5555],used[5555];

signed main(){
  int n,k;cin>>n>>k;
  REP(i,n)cin>>v[i];
  REP(i,n)cin>>c[i];
  vector<vector<int>>w;
  REP(i,n){
    if(used[i])continue;
    w.push_back(vector<int>(0));
    int tmp=0,sum=0;
    while(!used[i]){
      used[i]=1;
      w.back().push_back(c[i]);
      sum+=c[i];
      i=v[i]-1;
    }
    int K=k,S=w.back().size();
    if(sum>0&&K/S>0)tmp+=(K/S-1)*sum;
    if(K>S)K=K%S+S;
    REP(j,S){
      int tmp2=0;
      REP(l,K){
        tmp2+=w.back()[(j+l)%S];
        chmax(ans,tmp+tmp2);
      }
    }
  }
  cout<<ans<<endl;
}
