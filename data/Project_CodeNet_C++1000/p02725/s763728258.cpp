#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll K,N;
  cin >> K >> N;
  vector<ll> A(N);
  for(ll i=0;i<N;i++){
    cin >> A.at(i);
  }
  vector<ll> D(N);
  for(ll i=0;i<N;i++){
    if(i<N-1){
      D.at(i)=A.at(i+1)-A.at(i);
    }
    else if(i==N-1){
      D.at(i)=A.at(0)-A.at(i)+K;
    }
  }
  ll max=0;
  for(ll i=0;i<N;i++){
    if(D.at(i)>max){
      max=D.at(i);
    }
  }
  cout << K-max << endl;
}
