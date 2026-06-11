#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int a[n];
  int b[n];
  for(int i=0; i<n; i++) cin>>a[i]>>b[i];

  sort(a, a+n);
  sort(b, b+n);

  int ans;
  if(n%2==1) {
    int mi = a[(n-1)/2];
    int ma = b[(n-1)/2];
    ans = ma-mi+1;
  }
  else {
    double mi = (a[n/2-1]+a[n/2])/2.0;
    double ma = (b[n/2-1]+b[n/2])/2.0;
    ans = 2*(ma-mi) +1;
  }


  cout<<ans<<endl;

  return 0;
}