#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> Number(200000,0);
  for(ll i=0;i<N;i++){
    cin >> A.at(i);
    Number.at(A.at(i)-1)++;
  }
  ll Sum;
  for(ll x:Number){
    if(x!=0){
      Sum+=x*(x-1)/2;
    }
  }
  for(ll k=0;k<N;k++){
    cout << Sum-(Number.at(A.at(k)-1)-1) <<endl;
  }
}
