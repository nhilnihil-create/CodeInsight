#include <iostream>
using namespace std;

int main() {
  long long N; cin >> N;
  long long K; cin >> K;
  
  long long count = 0;
  while (N > 0){
    N /= K;
    count++;
  }
  cout << count << endl;
}