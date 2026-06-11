#include <bits/stdc++.h>

using namespace std;
const long long INF = 1LL <<60;  
int main(void){
  long long res=0;
  long long n,k;
  long long i,j;
  
  cin>>n>>k;
  long long p[n];
  for(i=0;i<n;i++){
    cin>>p[i];
  }
  sort(p,p+n);
  for(i=0;i<k;i++){
    res+=p[i];
  }
  cout<<res<<endl;
  return 0;
}