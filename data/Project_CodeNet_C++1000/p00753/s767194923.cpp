#include <iostream>
#include <cmath>

using namespace::std;

int main() {
  while(true) {
    int counter = 0;
    int counter2 = 0;
    int n = 0;
    cin >> n;
    if(n == 0) break;
    int prime[n+1];
    int prime2[2*n+1]; //1????´???°

    for(int i = 1; i <= n; ++i) {
      prime[i] = 1;
    }
    prime[1] = 0;
    for(int j = 2; j <= sqrt(n); ++j) {
      if (prime[j] == 1) {
        for(int k = 2; j*k <= n; ++k) {
          prime[j*k] = 0;
        }
      }
    }
    for(int i = 1; i <= n; ++i) {
      if(prime[i] == 1) {
        counter++;
      }
    }



    for(int i = 1; i <= 2*n; ++i) {
      prime2[i] = 1;
    }
    prime2[1] = 0;
    for(int j = 2; j <= sqrt(2*n); ++j) {
      if (prime2[j] == 1) {
        for(int k = 2; j*k <= 2*n; ++k) {
          prime2[j*k] = 0;
        }
      }
    }
    
     
    for(int i = 1; i <= 2*n; ++i) {
      if(prime2[i] == 1) {
        counter2++;
      }
    }

    cout << counter2-counter << endl;
  }
  return 0;
}