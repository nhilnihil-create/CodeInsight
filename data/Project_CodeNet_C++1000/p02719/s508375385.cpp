#include<bits/stdc++.h>
using namespace std;
int main(void){
  long long n,m; cin>>n>>m;
  if(n>m) cout<<min(abs(n-n/m*m),abs(n-n/m*m-m));
  else cout<<min(n,m-n);
  return 0;
}
