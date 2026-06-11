#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;

int main(){
  int X;
  cin >> X;
  for(ll i=0;i<150;++i){
    for(ll j=0;j<150;++j){
      if(pow(j,5)-pow(i,5)==X){
        cout << j << " " << i << endl;
        return 0;;
      }
      else if(pow(j,5)+pow(i,5)==X){
        cout << j << " " << -i << endl;
        return 0;
      }
    }
  }
  return 0;
}
