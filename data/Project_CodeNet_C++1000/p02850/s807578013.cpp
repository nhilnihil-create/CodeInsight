#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;

int main(){
  ll N,K=0,t=0;
  cin >> N;
  vector<vector<P>> A(N,vector<P>(0));
  vector<ll> C(N-1,0);
  queue<P> Q;
  rep(i,N-1){
    ll a,b;
    cin >> a >> b;
    A.at(a-1).push_back(P(i,b-1));
    A.at(b-1).push_back(P(i,a-1));
  }
  rep(i,N){
    if(A.at(i).size()>K){
      K=A.at(i).size();
      t=i;
    }
  }
  Q.push(P(t,0));
  while(!Q.empty()){
    P q=Q.front();
    ll l=0;
    Q.pop();
    rep(i,A.at(q.first).size()){
      if(i+1+l==q.second){
        l++;
      }
      if(C.at(A.at(q.first).at(i).first)!=0){
        l--;
        continue;
      }
      C.at(A.at(q.first).at(i).first)=i+1+l;
      Q.push(P(A.at(q.first).at(i).second,i+1+l));
    }
  }
  cout << K << endl;
  rep(i,N-1){
    cout << C.at(i) << endl;
  }
        
    
  
}
