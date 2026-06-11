#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<n;i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  long long ans=0;
  for (int i=1;i<n;i++) {
    int b=i/2;
    ans += a[b];
  }
  cout << ans << endl;
}
