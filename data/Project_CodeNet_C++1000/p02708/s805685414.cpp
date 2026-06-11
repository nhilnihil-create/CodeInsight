#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  cin >> N >> K;
 
  vector<long long>count(N-K+2);
  count.at(0) = 1;
  for (int i = 1; i < N-K+2; i++) {
    count.at(i) += count.at(i-1) + N - 2*(i-1);
  }
  
  long long S = 0;
  for (int i = 0; i < N-K+2; i++) {
    S += count.at(i);
    S = S % 1000000007;
  }
  cout << S << endl;
}
    
  