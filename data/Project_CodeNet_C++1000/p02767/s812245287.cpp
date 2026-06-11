#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  int x[n];
  int sum =0;
  for(int i = 0; i < n; i++){
    cin >> x[i];
  }
  int ans = 100000000;
  for(int i = 1; i <= 100; i++){
    int cnt = 0;
    for(int j = 0; j < n; j++){
      cnt += (x[j]-i)*(x[j]-i);
    }
    ans = min(ans,cnt);
  }
  cout << ans << endl;
}
