#include <bits/stdc++.h>
using namespace std;;

int main() {
  long N,K; cin >> N >> K;
  long a = N / K;
  long minP = N % K;
  long minN = (N % K - K) * (-1);
  
  cout << min(minP,minN) << endl;
}
  