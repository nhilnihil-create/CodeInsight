#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  int p[n];
  for(int i = 0; i < n;i++) cin >> p[i];
  int cnt = 0;
  for(int i = 0; i < n-1;i++){
    if(p[i] != i+1)cnt++;
  }
  if(cnt < 3) cout << "YES" << endl;
  else cout << "NO" << endl;
}
