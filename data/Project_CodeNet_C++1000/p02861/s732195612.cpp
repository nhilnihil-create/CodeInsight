#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll N;
  cin >> N;
  vector<ll> X(N);
  vector<ll> Y(N);
  for(ll i=0;i<N;i++){
    ll x,y;
    cin >> x >> y;
    X[i]=x;
    Y[i]=y;
  }
  ll tot=1;
  for(ll i=1;i<=N;i++){
    tot *= i;
  }
  double dist=0;
  vector<ll> Root(N,0);
  iota(Root.begin(),Root.end(),1);
  do{
    for(ll i=0;i<N-1;i++){
      dist += sqrt( (X[Root[i]-1]-X[Root[i+1]-1])*(X[Root[i]-1]-X[Root[i+1]-1]) + 
                  (Y[Root[i]-1]-Y[Root[i+1]-1])*(Y[Root[i]-1]-Y[Root[i+1]-1]));
    }
  }while(next_permutation(Root.begin(),Root.end()));
  cout << fixed << setprecision(10);
  cout << dist/(double)tot << endl;
}

