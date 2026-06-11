#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n; cin>>n;
  vector<int> l(n);
  for(auto& i:l) cin>>i;
  sort(l.begin(),l.end());
  int res=0;
  for(int i=0; i<(n-1); ++i) for(int j=i+1; j<n; ++j){
    int k=lower_bound(l.begin(),l.end(),l[i]+l[j])-l.begin();
    res+=max(k-(j+1),0);
  }
  cout<<res;
  return 0;
}