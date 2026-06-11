#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  vector<vector<ll>> A(3,vector<ll>(3));
  for(ll i=0;i<3;i++){
    for(ll j=0;j<3;j++){
      cin >> A.at(i).at(j);
    }
  }
  vector<vector<bool>> T(3,vector<bool>(3,false));
  ll N;
  cin >> N;
  for(ll k=0;k<N;k++){
    ll b;
    cin >> b;
    for(ll i=0;i<3;i++){
      for(ll j=0;j<3;j++){
        if(A.at(i).at(j)==b){
          T.at(i).at(j)=true;
        }
      }
    }
  }
  if((T.at(0).at(0)&&T.at(0).at(1)&&T.at(0).at(2)) || (T.at(1).at(0)&&T.at(1).at(1)&&T.at(1).at(2)) || (T.at(2).at(0)&&T.at(2).at(1)&&T.at(2).at(2)) ||
    (T.at(0).at(0)&&T.at(1).at(0)&&T.at(2).at(0)) || (T.at(0).at(1)&&T.at(1).at(1)&&T.at(2).at(1)) || (T.at(0).at(2)&&T.at(1).at(2)&&T.at(2).at(2)) ||
     (T.at(0).at(0)&&T.at(1).at(1)&&T.at(2).at(2)) || (T.at(0).at(2)&&T.at(1).at(1)&&T.at(2).at(0))){
    cout << "Yes" <<endl;
    return 0;
  }
  else{
    cout << "No" << endl;
    return 0;
  }
}
