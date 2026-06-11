#include <bits/stdc++.h>
using namespace std;
int main() {
	
  int k,ans=1; cin>>k;
  if (k%7==0){k/=7;}
  if(__gcd(10,k)!=1){
  	return cout<<-1<<endl, 0;
  }
  
  long long v = 1 % k;
  while (v!=0) {
    v=(10*v+1)% k;
    ans++;
}
  return cout<<ans<<endl, 0;
}