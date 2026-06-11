#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n; cin>>n;
  vector<int> p(n);
  for(auto& i:p) cin>>i;
  int m=n,res=0;
  for(auto& i:p) if(m>=i) ++res,m=i;
  cout<<res;
  return 0;
}