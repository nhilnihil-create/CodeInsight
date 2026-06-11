
#include <cstdio>
#include <iostream>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)

typedef long long ll;

bool usedD[200000+10];
bool usedV[200000+10];
int main(void) {
  int n, m;
  cin >> n >> m;
  int right = n;
  for(int left = 1; m > 0; ++left) {
    while(usedV[right] || usedD[right-left] || usedD[left-right+n] || (right - left == left - right + n)) {
      --right;
      if(right < 1) {
        right = n;
      }
    }
    --m;
    printf("%d %d\n", left, right);
    usedV[left] = true;
    usedV[right] = true;
    usedD[right-left] = true;
    usedD[left-right+n] = true;
    --right;
  }
  return 0;
}
