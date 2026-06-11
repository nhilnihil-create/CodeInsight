#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<cmath>
#include<numeric>
#include<queue>
using namespace std;

long long int mod = 1000000007;
vector<bool> isPrime(long long int n){
  vector<bool> prime(n+1, true);
  prime[0] = false;
  prime[1] = false;
  for(long long int i=2; i<=sqrt(n); i++){
    if( !prime[i] ) continue;
    for(long long int j=i*2; j<=n; j+=i){
      prime[j] = false;
    }
  }
  return prime;
}

int main(void) {

  int n;
  vector<bool> b = isPrime(2*123456+1);
  while( cin >> n ){
    if(n==0) break;
    int cnt = 0;
    for(int i=n+1; i<=2*n; i++){
      if( b[i] ) cnt++;
    }
    cout << cnt << endl;
  }


  return 0;
}