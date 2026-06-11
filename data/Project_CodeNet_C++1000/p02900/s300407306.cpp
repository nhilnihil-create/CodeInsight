#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
  if(b==0)return a;
  return gcd(b,a%b);
}
int sieve(long long max) {
    long long ans=max;
    int count=1;
    for (long long i = 2; i*i <= max; ++i)
        if(ans%i==0){
          count++;
          while(ans%i==0)ans/=i;
        }
    if(ans!=1)count++;
    return count;
}
int main(){
  long long A,B;cin>>A>>B;
  long long C=gcd(A,B);
  cout<<sieve(C)<<endl;
}