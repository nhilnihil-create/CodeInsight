#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n,a,b;
  cin>>n>>a>>b;
  long long i=n/(a+b);
  long long ans=i*a;
  long long sw=n%(a+b);
  if(sw>a)ans+=a;
  else ans+=sw;
  printf("%lld\n",ans);
}
