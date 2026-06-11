#include<bits/stdc++.h>
#define rep(i,n) for(i=0; i<n; ++i)
using namespace std;
int main(void){
  int b=0,i,N; cin >> N;
  vector<int> a(N);
  rep(i,N){ cin >> a[i]; b^=a[i];}
  rep(i,N) cout << (a[i]^b) << ' ';
  return 0;
}