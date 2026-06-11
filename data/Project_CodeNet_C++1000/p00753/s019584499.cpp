/*
  Chebyshev's Theorem
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1172&lang=jp
*/

#include <iostream>

using namespace std;

bool isPrime[456912];
int  already;

int main(void){
  already = 1;
  isPrime[0] = 0;
  isPrime[1] = 0;
  isPrime[2] = 1;

  for(int i = 3 ; i < 456912 ; i++){
    isPrime[i] = 1;
  }

  for(int i = 2 ; i < 456912 ; i++){
    if(isPrime[i] == 1){
      for(int j = 2 ; i * j < 456912 ; j++){
        isPrime[i * j] = 0;
      }
    }
  }

  while(1){
    int n;
    cin >> n;
    if(n == 0) break;

    int cnt = 0;

    for(int i = n + 1 ; i <= 2 * n ; i++){
      if(isPrime[i] == 1){cnt++;}
    }

    cout << cnt << endl;

  }

  return 0;
}