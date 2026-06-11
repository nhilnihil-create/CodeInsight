#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n, ans=0;
  cin >> n;
  int64_t a[n+1];
  map<int64_t, int64_t> m;
  for(int64_t i=1; i<=n; i++){
    cin >> a[i];
    if(!m.count(a[i]+i)) m[a[i]+i]=1;
    else m[a[i]+i]++;
    if(m.count(-a[i]+i)) ans+=m[-a[i]+i];
  }
  cout << ans;
  return 0;
}