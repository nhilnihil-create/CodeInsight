#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool kaibun(string S){
  string T=S;
  for(ll i=0;i<S.size();i++){
    T.at(i)=S.at(S.size()-1-i);
  }
  if(S==T){
    return true;
  }
  else {
    return false;
  }
}

int main() {
  string S;
  cin >> S;
  ll N=S.size();
  string S1="";
  string S2="";
  for(ll i=0;i<N;i++){
    if(i<(N-1)/2){
      S1+=S.at(i);
    }
    else if(i>=(N+3)/2-1){
      S2+=S.at(i);
    }
  }
  if(kaibun(S1) && kaibun(S2) && kaibun(S)){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
