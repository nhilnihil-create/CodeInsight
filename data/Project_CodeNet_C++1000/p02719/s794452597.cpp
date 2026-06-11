#include <bits/stdc++.h>
using namespace std;
int main(){
long long n,k;
  cin>>n>>k;
  long long a=n/k;
  n-=k*a;
  long long ans=min(n,abs(n-k));
  cout<<ans<<endl;
  return 0;
}
    
