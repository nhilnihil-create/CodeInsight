#include<bits/stdc++.h>
using namespace std;
const long long MOD=1000000007;


int main(){
  
  long long n,k;
  cin>>n>>k;
  long long a[n],r=0,l=0;
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      if(a[i]>a[j]) r++;
      else if(a[i]<a[j]) l++;
    }
  }
  long long ans=(k*r)%MOD+k*(k-1)/2%MOD*(l+r)%MOD;
  cout<<ans%MOD<<endl;
  
}