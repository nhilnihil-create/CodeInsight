#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  map<ll,ll> M;
  ll N;
  cin >> N;
  for(ll i=0;i<N;i++){
    ll a;
    cin >> a;
    if(M[a]==0){
      M[a]=1;
    }
    else{
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}