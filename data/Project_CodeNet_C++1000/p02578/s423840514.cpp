#include <bits/stdc++.h>

using namespace std;

const int SIZE_LIMIT = 2e5+5;
int arr[SIZE_LIMIT];

int main() {
  memset(arr, 0, sizeof(arr));

  int n = 0;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", arr+i);
  }

  long long ans = 0, maxA = arr[0];
  for (int i = 0; i < n; ++i) {
    if (arr[i] < maxA) {
      ans += maxA - arr[i];
    } else if (arr[i] > maxA) {
      maxA = arr[i];
    }
  }
  printf("%lld\n", ans);
  return 0;
}