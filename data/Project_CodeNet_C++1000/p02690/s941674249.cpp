#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
int main() {
  ll X,A,B;
  cin >> X;
  rep(i,300){
    rep(j,300){
      if(pow(i,5) - pow(j,5) == X){
        cout << i << " " << j << endl;
        return 0;
      }
      if(pow(-1*i,5) - pow(j,5) == X){
        cout << -i << " " << j << endl;
        return 0;
      }
      if(pow(i,5) - pow(-1*j,5) == X){
        cout << i << " " << -j << endl;
        return 0;
      }
      if(pow(-1*i,5) - pow(-1*j,5) == X){
        cout << -i << " " << -j << endl;
        return 0;
      }
    }
  }
  return 0;
}