#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n,a,b;scanf("%lld%lld%lld",&n,&a,&b);
  if(abs(a-b)%2==0) printf("%lld\n",abs(a-b)/2);
  else{
    long long e = min(min(a,b)-1,n-max(a,b))+1;
    printf("%lld\n",e+abs(a-b)/2);
  }
}