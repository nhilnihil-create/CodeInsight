#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n,k; cin >> n >> k;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  int t=0, nt=0;
  for(int i=0; i<n-1; i++) {
    for(int j=i+1; j<n; j++) {
      if(a[i]>a[j]) t++;
      else if(a[i]<a[j]) nt++;
    }
  }
  long long x = ((k+1)*k/2)%1000000007;
  long long y = (k*(k-1)/2)%1000000007;
  long long ans = (t*x+nt*y)%1000000007;
  cout << ans << endl;
  return 0;
}