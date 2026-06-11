#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  int n;cin>>n;
  vector<int> a(n+1);
  ll ans = 0;
  // 連想配列を使う map
  map<int,int> mp;
  for(int i=1; i<=n; i++) {
    cin>>a[i];
    ans+=mp[i-a[i]];
    mp[i+a[i]]++;
  }
  cout << ans << endl;
}
