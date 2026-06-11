#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N,K;
  cin >> N >> K;
  vector<long long> A(N + 1);
  
  for (long long i = 1; i < N + 2; i++) 
    A.at(i - 1) = i*(N + 1) - i*i + 1;
  
  long long ans = 0;
  for (long long j = K - 1; j < N + 1; j++) 
    ans += A.at(j);
  
  cout << ans%1000000007 << endl;
    
}