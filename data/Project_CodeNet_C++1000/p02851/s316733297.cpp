#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,k,ans=0,aaa=0;
  cin >> n >> k;
  map<long,long> x;
  map<long,long> y;
  vector<long> data(n);
  vector<long> a(n);
  for(long i=0;i<n;i++) cin >> a[i];

  for(long i=0;i<n;i++) {
    x[aaa]++;
    data[i]=aaa;
    if(i+1>=k) y[data[i-k+1]]++;
    aaa=(aaa+a[i]-1)%k;
    ans=ans+x[aaa]-y[aaa];
  }

  cout << ans << endl;
}