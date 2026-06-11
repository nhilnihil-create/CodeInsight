#include<bits/stdc++.h>
#define rep(i,x) for(int i=0; i<x; i++)
typedef long long ll;
using namespace std;
string T;

void solve(){

  for(int i=0; i<T.size(); i++){
    if(T[i]=='?'){
      T[i] = 'D';
    }
  }
  cout << T;
}





int main(){
  cin >> T;

  solve();

  return 0;
}
