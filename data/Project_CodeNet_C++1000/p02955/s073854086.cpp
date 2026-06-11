#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;
//const ll MOD=998244353;

int sum[505];

int main(){
  int N,K; cin>>N>>K;
  int A[N],tot=0;
  rep(i,N){
    cin>>A[i];
    tot+=A[i];
  }
  vector<int> V;
  for(int i=2;i*i<=tot;i++){
    if(tot%i==0){
      V.push_back(i);
      if(i*i!=tot) V.push_back(tot/i);
    }
  }
  V.push_back(tot);
  
  int ans=1;
  for(int v:V){
    vector<int> tmp;
    rep(i,N) tmp.push_back(A[i]%v);
    sort(tmp.begin(),tmp.end());
    rep(i,N+1) sum[i]=0;
    rep(i,N) sum[i+1]=sum[i]+tmp[i];
    int cnt=1e9;
    rep(i,N){
      int j=N-1-i;
      if(v*j==sum[N]) cnt=min(cnt,sum[i+1]);
    }
    if(cnt<=K) ans=max(ans,v);
  }
  cout<<ans<<endl;
  return 0;
}