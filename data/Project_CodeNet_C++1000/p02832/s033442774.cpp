#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n; cin>>n;
  vector<int> a(n);
  for(auto& i:a) cin>>i;
  int res=0,m=1;
  for(int i=0; i<n; ++i){
    if(a[i]==m) ++m;
    else ++res;
  }
  if(m==1) res=-1;
  cout<<res;
  return 0;
}
