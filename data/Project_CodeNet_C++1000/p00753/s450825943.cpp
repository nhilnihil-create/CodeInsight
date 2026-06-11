#include<bits/stdc++.h>
using namespace std;

vector<int> primes;

void sieve(){
  int n = 123457 * 2;
  bool isPrime[n] = {false};
  isPrime[0] = true;
  isPrime[1] = true;

  for(int i = 2; i <= n; i++){
    if(!isPrime[i]){
      primes.push_back(i);
      for(int j = i; j <= n; j += i){
        isPrime[j] = true;
      }
    }
  }
}
int main(){
  int n;
  sieve();
  while(cin >> n, n){
    int cnt = 0;
    for(int i = 0; i < primes.size(); i++){
      if(primes[i] > n && primes[i] <= 2 * n){
        cnt++;
      }
    }
    cout << cnt << endl;
  }
}