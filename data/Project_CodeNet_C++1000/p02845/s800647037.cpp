#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,ans=1;
  cin >> n;
  vector<long> a(n);
  vector<long> x(3);
  for(long i=0;i<n;i++) cin >> a[i];

  for(long i=0;i<n;i++) {
    long b=0;
    for(long j=0;j<3;j++) {
      if(x[j]==a[i]) {
        if(b==0) x[j]++;
        b++;
      }
    }
    ans=ans*b%1000000007;
  }

  cout << ans << endl;
}