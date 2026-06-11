// AOJ 1172
// Chebyshev's Theorem

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int prime[300001] = { 0 };
int MAX = 300000;

void make_prime(){
  int i, j;

  for (i = 2; i < MAX; i++) {
    prime[i] = 1;
  }

  for (i = 2; i * i < MAX; i++) {
    if (prime[i]){
      for (j = i * 2; j < MAX; j += i) {
        prime[j] = 0;
      }
    }
  }
}

int main() {
  make_prime();

  while (true) {
    int input;
    cin >> input;
    if (input == 0) { break; }
    int n = input;
    int count = 0;

    for (int i = n + 1; i <= n * 2; i++) {
      if (prime[i] == 1) { count++; }
    }

    cout << count << endl;
  }

  return 0;
}