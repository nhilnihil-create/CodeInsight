#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  long long N;
  long long K;
  cin >> N;
  cin >> K;
  
  long long I = N / K;
  cout << min(N - I * K, abs(N - (I + 1) * K)) << endl;
  return 0;
}