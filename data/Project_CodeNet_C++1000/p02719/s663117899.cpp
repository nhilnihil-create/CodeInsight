#include <bits/stdc++.h>
using namespace std;
int main(){
long long n,k;
  cin>>n>>k;
  long long ans;
  if(n>=k){
    long long a=n/k;
    n-=k*a;
    ans=min(n,abs(n-k));
    cout<<ans<<endl;
    return 0;
  }
  else{
    ans=min(n,abs(n-k));
    cout<<ans<<endl;
    return 0;
  }
  return 0;
}
    