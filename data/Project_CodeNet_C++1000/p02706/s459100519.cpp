#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;

int main(){
  int n,m;
  cin >> n >> m;
  if(m>n){
    cout << -1 << endl;
    return 0;
  }
  int t = 0;
  rep(i,m){
    int a;
    cin >> a;
    t +=a;
    if(t>n){
      cout << -1 << endl;
      return 0;
    }
  }
  cout << n-t << endl;
  return 0;
}
