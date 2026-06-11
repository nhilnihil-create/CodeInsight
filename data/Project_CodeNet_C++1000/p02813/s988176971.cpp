#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll N;
  cin >> N;
  vector<ll> P(N);
  vector<ll> Q(N);
  for(ll i=0;i<N;i++){
    ll p;
    cin >> p;
    P[i]=p;
  }
  for(ll i=0;i<N;i++){
    ll q;
    cin >> q;
    Q[i]=q;
  }
  vector<ll> Num(N);
  iota(Num.begin(),Num.end(),1);
  ll tot=1;
  for(ll i=1;i<=N;i++){
    tot*=i;
  }
  ll a=0;
  ll b=0;
  for(ll i=0;i<tot;i++){
    if(P==Num){
      a=i;
    }
    if(Q==Num){
      b=i;
    }
    next_permutation(Num.begin(),Num.end());
  }
  cout << abs(a-b) << endl;
}

