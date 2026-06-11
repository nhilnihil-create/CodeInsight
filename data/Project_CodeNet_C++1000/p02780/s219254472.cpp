#include<bits/stdc++.h>
typedef long double ld;
using namespace std;
int main(void){
  int n,k; cin>>n>>k;
  vector<int> p(n);
  for(auto& i:p) cin>>i;
  int m=0,j=0,cnt=0;
  for(int i=0; i<=n-k; ++i){
    if(i==0) for(int j=0; j<k; ++j) cnt+=p[j];
    else cnt+=p[i+k-1]-p[i-1];
    if(cnt>m) m=cnt,j=i;
  }
  ld res=0;
  for(int i=j; i<j+k; ++i) res+=((ld)1/p[i])*(p[i]*(p[i]+1))*0.5;
  printf("%Lf",res);
  return 0;
}