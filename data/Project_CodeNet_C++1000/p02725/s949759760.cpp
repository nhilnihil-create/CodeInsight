#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vec = vector<ll>;
using vecp = vector<P>;
using mat = vector<vec>;
using matp = vector<vecp>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define all(v) v.begin(), v.end()

//matp G(N);
void graphmake(ll E,matp &G){
  rep(i,E){
    ll a,b,c;
    cin >> a >> b >> c;
    G.at(a-1).push_back(P(b-1,c));
    G.at(b-1).push_back(P(a-1,c));//有向なら消す
  }
}
//vec d(N);
void dijkstra(ll s,vec &d, matp &G,ll V){
  priority_queue<P,vector<P>,greater<P>> que;
  rep(i,V) d.at(i)=INF;
  d.at(s)=0;
  que.push(P(0,s));
  while(!que.empty()){
    P p=que.top();
    que.pop();
    ll v=p.second;
    if(d.at(v)<p.first) continue;
    rep(i,G.at(v).size()){
      P e=G.at(v).at(i);
      if(d.at(e.first)>d.at(v)+e.second){
        d.at(e.first)=d.at(v)+e.second;
        que.push(P(d.at(e.first),e.first));
      }
    }
  }
}


int main(){
  ll K,N,m=0;
  cin >> K >> N;
  vec A(N);
  rep(i,N){
    cin >> A.at(i);
    if(i!=0){
      m=max(m,A.at(i)-A.at(i-1));
    }
    if(i==N-1){
      m=max(m,K+A.at(0)-A.at(i));
    }
  }
  cout << K-m << endl;
}
          
      