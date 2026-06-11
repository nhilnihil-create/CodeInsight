#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n,k; cin>>n>>k;
  vector<long long> h(n);
  for(auto& i:h) cin>>i;
  sort(h.begin(),h.end());
  long long res=0;
  for(int i=0; i<(n-k); ++i) res+=h[i];
  cout<<res;
  return 0;
}
