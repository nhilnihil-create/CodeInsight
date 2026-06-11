#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N,X,Y;
  cin >> N >> X >> Y;
  vector<vector<ll>> D(N,vector<ll>(N,0));
  vector<ll> Number(N-1,0);
  for(ll i=0;i<N;i++){
    for(ll j=i+1;j<N;j++){
      if((i+1<=X && j+1<=X) || (i+1>=Y && j+1>=Y)){
        D.at(i).at(j)=(j+1)-(i+1);
      }
      else if(X<i+1 && i+1<Y && X<j+1 && j+1<Y){
        D.at(i).at(j)=min((j+1)-(i+1),(i+1)-X+Y-(j+1)+1);
      }
      else if(i+1<=X && j+1>=Y){
        D.at(i).at(j)=X-(i+1)+(j+1)-Y+1;
      }
      else if(i+1<=X && X<j+1 && j+1<Y){
        D.at(i).at(j)=min((j+1)-(i+1) , X-(i+1)+1+Y-(j+1));
      }
      else if(X<i+1 && i+1<Y && Y<=j+1){
        D.at(i).at(j)=min((j+1)-(i+1) , (j+1)-Y+1+(i+1)-X);
      }
      Number.at(D.at(i).at(j)-1)++;
    }
  }
  for(ll k=0;k<=N-2;k++){
    cout << Number.at(k) << endl;
  }
}
