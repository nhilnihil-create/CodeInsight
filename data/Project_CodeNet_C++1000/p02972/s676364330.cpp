#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++) cin>>a[i];

  bool ans[n];
  for(int i=0; i<n; i++) ans[i]=false;

  for(int i=n; i>=1; i--) {
    if(n<2*i) ans[i-1] = a[i-1];
    else {
      int count = 0;
      int tmp = 2;
      while(i*tmp<=n) {
        if(ans[i*tmp-1]) count++;
        tmp++;
      }
      count += a[i-1];
      ans[i-1] = count%2;
    }
  }

  int sum = 0;
  for(int i=0; i<n; i++) {
    if(ans[i]) sum++;
  }

  cout<<sum<<endl;

  int cnt = 0;
  for(int i=0; i<n; i++) {

    if(ans[i]) {
      cnt++;
      if(cnt==sum) cout<<i+1<<endl;
      else cout<<i+1<<' ';
    }
  }

  return 0;
}