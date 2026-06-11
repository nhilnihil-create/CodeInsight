#include<bits/stdc++.h>
using namespace std;
int main(void){
  long long n; cin>>n;
  long long p,q;
  for(long long i=1; i*i<=n; ++i){
    long long r=n/i;
    if(r*i==n) p=i,q=r;
  }
  cout<<p+q-2;
  return 0;
}