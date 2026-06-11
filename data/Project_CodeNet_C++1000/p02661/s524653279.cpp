
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

int as[200000+10];
int bs[200000+10];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d%d", &as[i], &bs[i]);
  }
  sort(as, as + n);
  sort(bs, bs + n);
  int res;
  if(n % 2 == 0) {
    int l1 = as[n/2-1];
    int r1 = bs[n-1-(n/2-1)];
    int l2 = as[n/2];
    int r2 = bs[n-1-(n/2)];
    // cerr << "> " << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
    res = (r1-l1+1) + (r2-l2+1) - 1;
  } else {
    int left = as[n/2];
    int right = bs[n-1-n/2];
    // cerr << "> " << left << " " << right << endl;
    res = right - left + 1;
  }
  cout << res << endl;
  return 0;
}
