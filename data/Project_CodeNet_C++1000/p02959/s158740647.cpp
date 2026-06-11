#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int> a(n+1);
  for(int i=0; i<n+1; i++) cin >> a[i];
  vector<int> b(n);
  for(int i=0; i<n; i++) cin >> b[i];
  
  int64_t ans = 0;
  for(int i=0; i<n; i++) {
    if(a[i]<=b[i]) ans+=a[i], b[i]-=a[i], a[i]=0;
    else ans+=b[i], a[i]-=b[i], b[i]=0;
    
    if(b[i]>0) {
      if(b[i]>=a[i+1]) ans+=a[i+1], a[i+1]=0;
      else ans+=b[i], a[i+1]-=b[i];
    }
  }
  cout << ans << endl;
  return 0;
}