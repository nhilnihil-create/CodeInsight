#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }

  sort(a.begin(),a.end());
  long ans=a[n-1];
  int cnt=2;
  for(int i=2;i<n;i++){
    ans += a[n-cnt];
    // cout << a[n-cnt] << endl;
    if(i%2==1)cnt++;
  }

  cout << ans << endl;

  return 0;
}
