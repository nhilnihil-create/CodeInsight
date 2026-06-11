#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> v(n-1);
  for(int i=0; i<n-1; ++i) cin >> v[i];
  vector<int> ans(n);
  ans[0] = v[0];
  ans[n-1] = v[n-2];
  for(int i=1; i<n-1; ++i){
    ans[i] = min(v[i-1],v[i]);
  }
  int cnt = 0;
  for(int i=0; i<n; ++i) cnt += ans[i];
  cout << cnt << endl;
}