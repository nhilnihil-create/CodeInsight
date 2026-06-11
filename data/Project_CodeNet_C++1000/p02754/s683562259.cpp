#include <bits/stdc++.h>

using namespace std;

int main(){
  long long n,a,b;
  cin>>n>>a>>b;
  long long ans=a*(n/(a+b))*1ll;
  ans+=(n%(a+b)>a?a:n%(a+b));
  cout<<ans<<endl;
  return 0;
}