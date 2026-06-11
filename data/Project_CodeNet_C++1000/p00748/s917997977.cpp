#include <iostream>
#include <algorithm>
using namespace std;

int tr[300];
int sq[300];
int dp1[1000000];
int dp2[1000000];

int main() {

  for(int i=1; i < 300; i++) {
    tr[i] = tr[i-1] + i;
    sq[i] = sq[i-1] + tr[i];
  }
  for(int i=1; i < 1000000; i++) {
      dp1[i] = 1000111000;
      dp2[i] = 1000111000;
  }

  for(int i=0; i<1000000; i++) {
    for(int j=1; j < 300; j++) {
      if(i+sq[j] < 1000000) {
        dp1[i+sq[j]] = min(dp1[i] + 1, dp1[i+sq[j]]);
        if(sq[j]%2 == 1) {
          dp2[i+sq[j]] = min(dp2[i] + 1, dp2[i+sq[j]]);
        }
      }
    }
  }

  int n;
  while(cin >> n, n) {
    cout << dp1[n] << " " << dp2[n] << endl;
  }

  return 0;
}