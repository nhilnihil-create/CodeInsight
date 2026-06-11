#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,l;
  int res = 0;
  cin >> n >> l;
  vector<int> t(n+1);
  for(int i = 1; i <= n; ++i){
    t[i] = l + i - 1;
  }
  int p = 100000;
  for(int i = 1; i <= n; ++i){
    p = min(p,abs(t[i]));
  }
  //cout << p << endl;
  for(int i = 1; i <= n; ++i){
    if(t[i] != p && t[i] != -1 * p){
      res += t[i];
    }
  }
  cout << res << endl;
}