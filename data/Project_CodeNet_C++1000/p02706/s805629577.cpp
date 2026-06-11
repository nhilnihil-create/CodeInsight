#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m; cin >> n >> m;
  vector<int> a(m);
  
  int sum = 0;
  
  for(int i = 0; i < m; i++){
  	cin >> a[i];
  	sum += a[i];
  }
  //cout << sum << endl;
  if(sum <= n) cout << n - sum << endl;
  else cout << -1 << endl;
}