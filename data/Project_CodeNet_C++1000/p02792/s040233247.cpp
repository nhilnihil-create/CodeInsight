#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n; cin>>n;
  int p[10][10]={{}},q[10][10]={{}},ten=1;
  for(int i=1; i<=n; ++i){
    if(i-ten*10==0) ten*=10;
    int t=i/ten,b=i%10;
    ++p[t][b]; ++q[b][t];
  }
  int res=0;
  for(int i=0; i<10; ++i) for(int j=0; j<10; ++j) res+=p[i][j]*q[i][j];
  cout<<res;
  return 0;
}