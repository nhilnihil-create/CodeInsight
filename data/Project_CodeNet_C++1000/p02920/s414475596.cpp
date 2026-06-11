#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()
 
//vector<vector<ll>> G(N,vector<ll>(0));
void no_cost_graphmake(ll E,vector<set<ll>> &G){
  rep(i,E){
    ll a,b;
    cin >> a >> b;
    G.at(a-1).insert(b-1);
  }
}

int main(){
  ll N;
  cin >> N;
  vector<ll> S((ll)pow(2,N));
  rep(i,(ll)pow(2,N)) cin >> S.at(i);
  sort(all(S));
  vector<ll> s;
  rep(i,(ll)pow(2,N)){
    ll k=1,x=S.at((ll)pow(2,N)-1-i);
    while(k+i<(ll)pow(2,N)&&x==S.at((ll)pow(2,N)-1-i-k)){
      k++;
    }
    i+=k-1;
    s.push_back(k);
  }
  vector<vector<ll>> x((ll)s.size()+1,vector<ll>(N+1,0));
  x.at(0).at(N)=1;
  rep(i,(ll)s.size()){
    ll t=0;
    rep(j,N+1){
      t+=x.at(i).at(j);
    }
    if(s.at(i)>t){
      cout << "No" << endl;
      return 0;
    }
    ll y=N;
    rep(j,s.at(i)){
      while(x.at(i).at(y)==0){
        y--;
      }
      x.at(i).at(y)--;
      rep(k,y){
        x.at(i+1).at(k)++;
      }
    }
    rep(j,N){
      x.at(i+1).at(j)+=x.at(i).at(j);
    }
  }
  cout << "Yes" << endl;
  
}