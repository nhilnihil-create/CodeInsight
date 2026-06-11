#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 123456*2;

bool isPrime[MAX_N];

void make() {
  fill(isPrime, isPrime+MAX_N, true);
  isPrime[0] = isPrime[1] = false;
  for(int i = 2; i < MAX_N; ++i) {
    if(!isPrime[i]) continue;
    for(int j = i*2; j < MAX_N; j += i)  {
      isPrime[j] = false;
    }
  }
}

int main() {
  make();
  int n;
  while((cin >> n) && n) {
    int cnt = 0;
    for(int i = n+1; i <= n*2; ++i) {
      if(isPrime[i]) ++cnt;
    }
    cout << cnt << endl;
  }
  return 0;
}