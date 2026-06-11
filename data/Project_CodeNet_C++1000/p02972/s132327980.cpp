#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 1e18;
#define all(v) v.begin(), v.end()

int main(){
  ll N;
  cin >> N;
  vector<ll> A(N),B(N,0);
  rep(i,N) cin >> A.at(i);
  queue<ll> Q;
  rep(i,N){
    ll k=2,x=0;
    while(k*(N-i)<=N){
      x+=B.at(k*(N-i)-1);
      k++;
    }
    if(x%2!=A.at(N-1-i)){
      B.at(N-1-i)=1;
      Q.push(N-i);
    }
  }
  cout << Q.size() << endl;
  while(!Q.empty()){
    cout << Q.front() << " ";
    Q.pop();
  }
  cout << endl;
}