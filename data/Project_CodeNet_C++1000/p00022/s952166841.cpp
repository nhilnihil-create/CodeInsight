#include <iostream>
#include <limits.h>
using namespace std;

int a[5001] = {0};
int S[5001] = {0};

int main() {
  int n;
  while(cin >> n) {
  if(n == 0) break;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  S[0] = 0;
  for(int i = 1; i <= n; i++) {
    S[i] = S[i-1] + a[i-1];
  }
  

  int maxsum = INT_MIN;
  int sum;
  for(int i = 0; i <= n-1; i++){
    for(int j = i + 1; j <= n;j++) {
      sum = S[j] - S[i];
      if(sum > maxsum)
	maxsum = sum;
    }
  }
  cout << maxsum << endl;
  }
}