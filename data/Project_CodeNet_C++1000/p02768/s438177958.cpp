#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1000000007;

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}


int main(){
  long long N,A,B;
  cin>> N>>A>>B;
  long long total=0;
  total=modpow(2,N,MOD);
  total--;
  
  long long temp=1;
  for(int i=N;i>=N-A+1;i--){
    temp=temp*i%MOD;
  }
  long long temp2=1;
  for(int i=1;i<=A;i++){
    temp2=temp2*i%MOD;
  }
  temp2=modpow(temp2,MOD-2,MOD);
  temp=temp*temp2%MOD;
  
  long long temp3=1;
  for(int i=N;i>=N-B+1;i--){
    temp3=temp3*i%MOD;
  }
  long long temp4=1;
  for(int i=1;i<=B;i++){
    temp4=temp4*i%MOD;
  }
  temp4=modpow(temp4,MOD-2,MOD);
  temp3=temp3*temp4%MOD;
  
  if(total-temp-temp3<0){
    total=total+MOD;
  }
  if(total-temp-temp3<0){
    total=total+MOD;
  } 
  
  //cout<<total<<" "<<temp<<" "<<temp3<<endl;
  cout<<total-temp-temp3<<endl;

  return 0;
}


