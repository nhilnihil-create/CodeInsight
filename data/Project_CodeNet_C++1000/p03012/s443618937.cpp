#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> w(n);
  for(int i = 0; i < n; i++) cin >> w[i];
  int ans = 1e9;
  for(int i = 1; i < n; i++){
    int l = 0, r = 0;
    for(int j = 0; j < i; j++){
      l += w[j];
    }
    for(int j = i; j < n; j++){
      r += w[j];
    }
    ans = min(ans, abs(l - r));
  }
  cout << ans << endl;
  return 0;
}