#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;
//const ll MOD=998244353;

vector<pair<ll,int>> V;
map<ll,int> mp;
ll N;

int rec(int ind,ll K){
  if(ind==V.size()){
    if(K==1) return 0;
    ll X=N;
    while(X%K==0&&X>1) X/=K;
    if(X%K==1) return 1;
    else return 0;
  }
  int ret=0;
  ll a=1;
  for(int i=0;i<=V[ind].second;i++){
    ret+=rec(ind+1,K*a);
    a*=V[ind].first;
  }
  return ret;
}

int main(){
  cin>>N;
  ll X=N;
  for(ll i=2;i*i<=X;i++){
    if(X%i) continue;
    int cnt=0;
    while(X%i==0) cnt++,X/=i;
    V.push_back({i,cnt});
  }
  if(X>1) V.push_back({X,1});
  ll ans=rec(0,1);
  
  X=N-1;
  for(ll i=2;i*i<=X;i++){
    while(X%i==0){
      mp[i]++;
      X/=i;
    }
  }
  if(X>1) mp[X]++;
  ll res=1;
  for(auto m:mp) res*=(m.second+1);
  ans+=res-1;

  cout<<ans<<endl;
  return 0;
}
