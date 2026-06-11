#include<bits/stdc++.h>
using namespace std;
int main(void){
  long long res,n,k; cin>>n>>k;
  res=(k*(k-1)*(2*k-1)-(n+1)*(n+2)*(2*n+3))/6+(n+1)*((n+1)*(n+2)-k*(k-1))/2+n-k+2;
  cout<<res%1000000007;
  return 0;
}