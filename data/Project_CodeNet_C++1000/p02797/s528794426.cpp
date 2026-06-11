#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main(){
  int n,k,s; cin >>n >>k >>s;
  rep(i,n){
    if(i<k) cout << s;
    else {
      if(s<1e9) cout << s+1;
      else cout << 1;
    }
    cout << " ";
  }
  cout << endl;
  return 0;
}