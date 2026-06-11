#include<bits/stdc++.h>
using namespace std;
int main(void){
  long long n,sum=0; cin>>n;
  vector<long long> a(n),b(n,0),c(n);
  for(int i=0; i<n; ++i){ cin>>a[i]; --a[i]; ++b[a[i]];}
  for(int i=0; i<n; ++i){ c[i]=b[a[i]]*(b[a[i]]-1)/2; sum+=b[i]*(b[i]-1)/2;}
  for(int i=0; i<n; ++i) cout<<sum-c[i]+(b[a[i]]-1)*(b[a[i]]-2)/2<<endl;
  return 0;
}
