#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n,x,y; cin>>n>>x>>y;
  vector<int> a(n,0);
  for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j){
    int d=min(j-i,abs(x-i)+abs(y-j)+1);
    ++a[d];
  }
  for(int i=1; i<n; ++i) cout<<a[i]<<endl;
  return 0;
}
