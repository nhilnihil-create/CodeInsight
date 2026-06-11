#include <bits/stdc++.h>

#define ABS(x) ((x) > 0 ? (x) : -(x))
using namespace std;

const int ARR_SIZE = 1e2+5;

//int arr[ARR_SIZE];



int main() {
  long long x, k, d;
  scanf("%lld%lld%lld", &x, &k, &d);

  long long maxMove = ABS(x) / d;

  if (maxMove >= k) {
    if (x > 0) printf("%lld\n", x-k*d);
    else printf("%lld\n", -x-k*d);
  } else if ((k - maxMove)%2){
    if (x > 0) printf("%lld\n", d-x+maxMove*d);
    else printf("%lld\n", d+x+maxMove*d);
  } else {
    if (x > 0) printf("%lld\n", x-maxMove*d);
    else printf("%lld\n", -x-maxMove*d);
  }
  return 0;
}