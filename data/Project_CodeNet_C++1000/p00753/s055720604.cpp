#include <iostream>
using namespace std;
#define MAX_N 1234560

bool isPrime[MAX_N * 2 + 1];

int main(void){
  for(int i = 0; i <= MAX_N * 2; i++) isPrime[i] = true;
  isPrime[0] = isPrime[1] = false;
  for(int i = 2; i * i <= MAX_N * 2; i++){
    if(isPrime[i]){
      for(int j = i * i; j <= MAX_N; j += i) isPrime[j] = false;
    }
  }
  int n, cnt;
  while(true){
    cin >> n;
    if(n == 0) break;
    cnt = 0;
    for(int i = n + 1; i <= 2 * n; i++){
      if(isPrime[i]) cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}