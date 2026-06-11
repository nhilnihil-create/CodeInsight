#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char *argv[])
{
  for(;;) {
    int n;
    cin >> n;
    if(n==0) break;
    int n22 = n*2+2;
    bool prime[n*2+2];
    for(int i = 0; i < n22; i++) {
      prime[i] = true;
    }
    prime[0] = false;
    prime[1] = false;
    for(int p = 2; p < n22; p++) {
      if(prime[p]) {
        for(int k = p+p; k < n22; k+=p) {
          prime[k] = false;
        }
      }
    }
    int cnt = 0;
    for(int i = n+1; i <= 2*n; i++) {
      if(prime[i]) cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}