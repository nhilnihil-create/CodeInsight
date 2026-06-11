#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n; cin>>n;
  vector<int> p(n+1,1);
  for(int i=2; i<=n; ++i) for(int j=1; j*i<=n; ++j) ++p[j*i];
  long long res=0;
  for(long long i=1; i<=n; ++i) res+=i*p[i];
  cout<<res<<endl;
  return 0;
}