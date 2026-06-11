#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll X,N;
  cin >> X >> N;
  
  if(N==0){
    cout << X << endl;
    return 0;
  }
  
  vector<ll> P(N);
  for(ll i=0;i<N;i++){
    cin >> P.at(i);
  }
  
  int t=0;
  for(ll i=0;i<3*N;i++){
    if(i%2==0){
      t=(i+1)/2;
    }
    else if(i%2==1){
      t=-(i+1)/2;
    }
    bool f=true;
    for(ll j=0;j<N;j++){
      if(P.at(j)-X==t){
        f=false;
      }
    }
    if(f){
      cout << X+t <<endl;
      return 0;
    }
  }
}
