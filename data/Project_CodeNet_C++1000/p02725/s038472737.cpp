#include <bits/stdc++.h>

#define N_Max 200001
#define A_Max 1000001
using namespace std;
const long long INF = 1LL <<60;

int main(void){
  long long k,n;
  long long res;
  long long i,j;
  
  cin>>k>>n;
  long long a[n];
  for(i=0;i<n;i++){
    cin>>a[i];
  }
  
  res=a[0]+k-a[n-1];
  for(i=1;i<n;i++){
    res=max(res,a[i]-a[i-1]);
  }

  res=k-res;
  
  cout<<res<<endl;
  
  return 0;
  
}      