#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 1000000007;

ll pow(ll x,ll y){
  if(y==0){
    return 1;
  }else if(y==1){
    return x%MOD;
  }else if(y%2==0){
    return pow(x,y/2)*pow(x,y/2)%MOD;
  }else{
    return pow(x,y-1)*x%MOD;
  }
}

int main(){
  string S;cin >> S;
  if(S=="ARC"){
    cout << "ABC" << endl;
  }else{
    cout << "ARC" << endl;
  }
}