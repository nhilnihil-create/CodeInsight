#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n; cin>>n;
  vector<int> d(n);
  for(auto& i:d) cin>>i;
  int res=0;
  for(int i=0; i<n; ++i) for(int j=i+1; j<n; ++j)
    res+=d[i]*d[j];
  cout<<res;
  return 0;
}