#include <bits/stdc++.h>
#define int long long
using namespace std;

bool isprime[1000005];

void init(){
  
  for(int i=0;i<1000005;i++) isprime[i] = true;
  
  isprime[0] = isprime[1] = false;
  
  for(int i=2;i<1000005;i++){
    if( !isprime[i] ) continue;
    for(int j=i*2;j<1000005;j+=i){
      isprime[j] = false;
    }
  }
  
}

bool isPrime(int num){
  
  if( num == 1 ) return false;
  
  for(int i=2;i*i<=num;i++){
    if( num % i == 0 ) return false;
  }
  
  return true;
}

signed main(){
  
  init();
  
  int n;
  cin >> n;
  
  if( isPrime(n) == true ){
    cout << 1 << endl;
    return 0;
  }
  
  int ans = 0;
  
  for(int i=0;i<1000005;i++){
    
    if( !isprime[i] ) continue;
    
    int cnt = 0;
    
    while( n % i == 0 ){
      n /= i;
      cnt++;
    }
    
    int sum = cnt;
    
    for(int j=1;j<=sum;j++){
      
      if( j <= cnt ){
	cnt -= j;
	ans++;
      }
      
    }
    
  }
  
  if( isPrime( n ) == true ) ans++;
  
  cout << ans << endl;
  
  return 0;
}
