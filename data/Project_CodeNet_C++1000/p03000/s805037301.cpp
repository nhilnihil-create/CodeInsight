#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n, x;
  cin >> n >> x;
  vector<int> vec(n+1);
  vec[0] = 0;
  rep(i,n){
    int l;
    cin >> l;
    vec[i+1] = vec[i] + l;
  }
  int ans = 0;
  rep(i,n+1){
    if(vec[i] <= x){
      ans++;
    }
  }
  cout << ans;
    
  return 0;
}