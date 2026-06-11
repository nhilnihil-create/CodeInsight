#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 300000;

bool is_prime[N+1];
vector<int> prime;

void sieve(){
  for(int i=0;i<=N;i++) is_prime[i] = true;
  is_prime[0] = is_prime[1] = false;
  for(int i=2;i<=N;i++){
    if(is_prime[i]){
      prime.push_back(i);
      for(int j=2*i;j<=N;j+=i) is_prime[j] = false;
    }
  }
}

main(){
  sieve();
  int n;
  while(cin >> n && n){
    cout << distance(upper_bound(prime.begin(), prime.end(), n), upper_bound(prime.begin(), prime.end(), 2*n)) << endl;
  }
}