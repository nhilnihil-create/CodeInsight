#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> w(n);
  for(int i = 0; i < n; ++i){
    cin >> w[i];
  }
  int res = 1000000;
  int c1,c2;
  for(int i = 0; i < n; ++i){
    c1 = 0;
    c2 = 0;
    for(int j = 0; j < n; ++j){
      if(j <= i){
        c1 += w[j];
      }else{
        c2 += w[j];
      }
    }
    res = min({res,abs(c1-c2)});
  }
  cout << res;
}