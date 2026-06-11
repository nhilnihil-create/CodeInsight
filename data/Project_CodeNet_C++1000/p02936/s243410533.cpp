#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

//
void no_cost_graphmake(ll E,vector<vector<ll>> &G){
  rep(i,E){
    ll a,b;
    cin >> a >> b;
    G.at(a-1).push_back(b-1);
    G.at(b-1).push_back(a-1);
  }
}

int main(){
  ll N,Q;
  cin >> N >> Q;
  vector<vector<ll>> G(N,vector<ll>(0));
  no_cost_graphmake(N-1,G);
  vector<ll> A(N,0);
  rep(i,Q){
    ll p,x;
    cin >> p >> x;
    A.at(p-1)+=x;
  }
  queue<ll> Queue;
  vector<ll> U(N,0);
  Queue.push(0);
  U.at(0)=1;
  while(!Queue.empty()){
    ll i=Queue.front();
    Queue.pop();
    rep(j,G.at(i).size()){
      if(U.at(G.at(i).at(j))==0){
        A.at(G.at(i).at(j))+=A.at(i);
        Queue.push(G.at(i).at(j));
        U.at(G.at(i).at(j))=1;
      }
    }
  }
  rep(i,N){
    cout << A.at(i) << " ";
  }
  cout << endl;
}
