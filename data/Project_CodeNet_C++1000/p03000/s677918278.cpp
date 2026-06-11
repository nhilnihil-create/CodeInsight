#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,x;
  cin >> n >> x;
  vector<int> l(n);
  for (int i = 0;i < n;i++){
    cin >> l[i];
  }
  
  vector<int> d(n+1);
  d[0] = 0;
  for (int i = 1;i < n+1;i++){
    d[i] = d[i-1] + l[i-1];
  }
  
  int ans = 0;
  for (int i = 0;i < n+1;i++){
    if (d[i] <= x){
      ans++;
    }
  }
  
  cout << ans << endl;
}