#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  int sum = 0;
  for(int i = 0; i < n; i++) sum += a[i];
  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(sum <= 4*m*a[i]) ans++;
  }
  if(ans >= m) cout << "Yes" << endl;
  else cout << "No" << endl;
}