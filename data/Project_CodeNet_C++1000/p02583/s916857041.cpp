#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < n; ++i)


main() {
  int n;cin>>n;
  int L[n];rep(i,n) cin>>L[i];
  sort(L,L+n);
  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
      for(int k=0;k<j;k++){
        if(L[i]!=L[j] && L[j]!=L[k] && L[k]+L[j]>L[i]){
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}