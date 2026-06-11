#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;

    

int main(){
  ll N,K,C,t=0;
  string S;
  cin >> N >> K >> C >> S;
  vector<ll> L(K),R(K);
  rep(i,N){
    if(S.at(i)=='o'){
      L.at(t)=i;
      t++;
      i+=C;
    }
    if(t==K){
      break;
    }
  }
  t=K-1;
  rep(i,N){
    if(S.at(N-i-1)=='o'){
      R.at(t)=N-i-1;
      t--;
      i+=C;
    }
    if(t==-1){
      break;
    }
  }
  rep(i,K){
    if(L.at(i)==R.at(i)){
      cout << L.at(i)+1 << endl;
    }
  }
      
}