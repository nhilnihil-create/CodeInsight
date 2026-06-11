#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n,x,t;
  cin >> n >> x >> t;
  int ans = 0;
  
  if(n%x==0){
    ans = (n / x) * t;
  }
  else{
    ans = (n / x) * t + t;
  }
  cout << ans << endl;
  return 0;
}