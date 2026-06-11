#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

//vector<vector<ll>> G(N,vector<ll>(0));
void no_cost_graphmake(ll E,vector<vector<ll>> &G){
  rep(i,E){
    ll a,b;
    cin >> a >> b;
    G.at(a-1).push_back(b-1);
    G.at(b-1).push_back(a-1);//有向なら消す
  }
}

int main(){
  ll N,K,ans=1;
  cin >> N >> K;
  vector<vector<ll>> G(N,vector<ll>(0));
  no_cost_graphmake(N-1,G);
  queue<P> Q;
  Q.push(P(0,0));
  while(!Q.empty()){
    ll x=Q.front().first,y=Q.front().second;
    Q.pop();
    if(x==0){
      ans*=K;
      rep(i,G.at(x).size()){
        ans*=K-1-i;
        ans%=MOD;
        Q.push(P(G.at(x).at(i),x));
      }
    }else{
      rep(i,G.at(x).size()-1){
        ans*=K-2-i;
        ans%=MOD;
      }
      rep(i,G.at(x).size()){
        if(y==G.at(x).at(i)) continue;
        Q.push(P(G.at(x).at(i),x));
      }
    }
  }
  cout << ans << endl;
}