#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n, k;
  int a[500], b[500];
  long long S = 0;
  
  scanf("%d %d", &n, &k);
  
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    S += a[i];
  }
  
  vector<long long> div;
  for (long long i = 1; i * i <= S; i++) {
   	if (S % i == 0) {
      div.push_back(i);
      if (i != S / i) div.push_back(S / i);
    }
  }
  
  sort(div.rbegin(), div.rend());
  
  for (int i = 0; i < div.size(); i++) {
    for (int j = 0; j < n; j++) {
      b[j] = a[j] % div[i];
    }
    sort(b, b + n);
    long long cnt1 = 0, cnt2 = 0;
    for (int j = 0; j < n; j++) {
      if (cnt1 + b[j] <= k) cnt1 += b[j];
      else cnt2 += (div[i] - b[j]) % div[i];
    }
    if (max(cnt1, cnt2) <= k) {
      printf("%lld\n", div[i]);
      break;
    }
  }
  
  return 0;
}