#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll N;
  string S;
  cin >> N >> S;
  if( N%2==1 ){
    cout << "No" << endl;
    return 0;
  }
  string T="";
  for(ll i=0;i<N/2;i++){
    T+=S.at(i);
  }
  if(S==T+T){
    cout << "Yes" << endl;
    return 0;
  }
  else{
    cout << "No" << endl;
    return 0;
  }
}

