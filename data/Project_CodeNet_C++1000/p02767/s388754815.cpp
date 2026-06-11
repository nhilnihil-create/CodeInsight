#include <iostream>
using namespace std;

int main() {
  long long N; cin >> N;
  long long X[N];
  for (int i = 0; i < N; i++) cin >> X[i];
  
  long long min_ = 1000000000000;
  for (long long i = 0; i <= 100; i++){
    long long count = 0;
    for (long long j = 0; j < N; j++){
      count += (X[j] - i) * (X[j] - i);
    }
    min_ = min(min_, count);
  }
  cout << min_ << endl;
}