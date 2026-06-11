#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int MOD=1e9+7;
const long double Pi=acos(-1);
using  P=pair<ll,ll>;
vector<ll> ans;
vector<vector<ll>> vec;
unordered_map<ll,ll> mp;
vector<bool> tf;
ll dp[200020];
void dfs(ll a){
  for(ll i=0;i<(ll)vec.at(a).size();i++){
    if(tf.at(vec.at(a).at(i))==false){
      dp[vec.at(a).at(i)+1]=dp[a+1]+mp[vec.at(a).at(i)+1];
      tf.at(vec.at(a).at(i))=true;
      dfs(vec.at(a).at(i));
    }
  }
}
int main(){
  ll N,Q;
  cin>>N>>Q;
  tf.resize(N);
  ans.resize(N);
  vec.resize(N,vector<ll>(0));
  for(ll i=0;i<N-1;i++){
    ll a,b;
    cin>>a>>b;
    vec.at(a-1).push_back(b-1);
    vec.at(b-1).push_back(a-1);
  }
  for(ll i=0;i<Q;i++){
    ll a,b;
    cin>>a>>b;
    mp[a]+=b;
  }
  tf.at(0)=true;
  dp[1]=mp[1];
  dfs(0);
  for(ll i=0;i<N;i++){
    cout<<dp[i+1]<<" ";
  }
}