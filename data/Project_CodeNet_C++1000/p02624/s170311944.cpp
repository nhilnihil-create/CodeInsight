#include<iostream>
using namespace std;


int main(){
  
  long long n; cin >> n;
  
  long long  *divisor = new long long[n+1];
  for(long long i=0;i<=n;i++)divisor[i] = 0;
  
  
  for(long long i=1;i<=n;i++){
    for(long long j=i;j<=n;j+=i)divisor[j]++;
  }
  
  unsigned long long sum = 0;
  for(int i=1;i<=n;i++){
     
      sum +=  (i*divisor[i]);
  }
    delete divisor;
  
  printf("%llu\n",sum);
  
  
  
  
  return 0;
}