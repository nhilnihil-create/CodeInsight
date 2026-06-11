#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
long long N, A[1 << 18];
int main() {
  cin >> N; long long S = 0;
  for (int i=1; i<=N; i++) {cin >> A[i]; S+=A[i];}

  long long minx=S, sum=0;
  for (int i=1; i<=N; i++) {
    sum+=A[i];
    minx=min(minx,abs(sum-(S-sum)));
  }
  cout << minx << endl;
  return 0;
}