#include<bits/stdc++.h>
using namespace std;
int main(void){
  long long a,b,k; cin>>a>>b>>k;
  if(a+b<=k) a=b=0;
  else if(a<k) b-=(k-a),a=0;
  else a-=k;
  printf("%lld %lld\n",a,b);
  return 0;
}
  