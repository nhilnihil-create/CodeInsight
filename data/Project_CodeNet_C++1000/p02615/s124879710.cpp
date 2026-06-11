#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int64_t friends[n];
  for(int i=0; i<n; i++) cin>>friends[i];

  int64_t ans = 0;
  sort(friends, friends+n, greater<int64_t>());

  // for(int i=0; i<n-1; i++) ans += friends[i];
  ans = friends[0];
  int count = 1;
  if(n%2==0) {
    for(int i=1; i<n/2; i++) ans+=friends[i]*2;
  }
  else {
    for(int i=1; i<n/2; i++) ans+=friends[i]*2;
    ans += friends[n/2];
  }


  cout<<ans<<endl;

  return 0;
}