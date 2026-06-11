#include <bits/stdc++.h>
using namespace std;

#define int long long
template<typename T>
void chmax(T &a,T b){
  if(a<b)a=b;
}
int ans=-1e18;

signed main(){
  int n,k;cin>>n>>k;
  vector<int> v(n),c(n);
  for(int i=0;i<n;i++){cin>>v[i];v[i]--;}
  for(int i=0;i<n;i++)cin>>c[i];
  vector<vector<int>>w;
  vector<int>used(n,0);
  for(int i=0;i<n;i++){
    if(used[i])continue;
    int tmp=0,sum=0;
    w.push_back(vector<int>(0));
    while(!used[i]){
      used[i]=1;
      w.back().push_back(c[i]);
      sum+=c[i];
      i=v[i];
    }
    int K=k,S=w.back().size();
    if(sum>0&&K/S>0)tmp+=(K/S-1)*sum;
    if(K>S)K=K%S+S;
    for(int j=0;j<S;j++){
      int tmp2=0;
      for(int l=0;l<K;l++){
        tmp2+=w.back()[(j+l)%S];
        chmax(ans,tmp+tmp2);
      }
    }
  }
  cout<<ans<<endl;
}
