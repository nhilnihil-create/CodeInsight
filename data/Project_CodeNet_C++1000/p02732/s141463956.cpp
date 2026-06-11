#include <bits/stdc++.h>
 
using namespace std;
const long long INF = 1LL <<60;  
 
int main(void){
  long c[200001]={};
  long long res=0;
  long long i,j,k;
  long tmp;
  long n;
  
  cin>>n;
  long a[n];
  for(i=0;i<n;i++){
    cin>>a[i];
    c[a[i]]++;
  }
  for(i=1;i<=n;i++){
    res+=c[i]*(c[i]-1)/2;
  }
  for(i=0;i<n;i++){
    cout<<res-(c[a[i]]-1)<<endl;
  }
  
  //cout<<res<<endl;
  return 0;
}