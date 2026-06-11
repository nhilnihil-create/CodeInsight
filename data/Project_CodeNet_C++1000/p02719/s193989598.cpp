#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N, K;
  cin >> N >> K;
  long long m=N/K;
  cout << min(N-K*m, K*(m+1)-N) << endl;
}