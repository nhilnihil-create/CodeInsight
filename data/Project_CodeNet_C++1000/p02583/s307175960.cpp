#include <bits/stdc++.h>

using namespace std;

const int ARR_SIZE = 1e2+5;

int arr[ARR_SIZE];

int main() {
  int n = -1;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", arr+i);
  }

  sort(arr, arr+n);

  int ans = 0;
  for (int i = 0; i < n-2; ++i) {
    for (int j = i+1; j < n-1; ++j) {
      if (arr[j] == arr[i]) continue;

      for (int k = j+1; k < n; ++k) {
        if (arr[k] == arr[j]) continue;

        if (arr[i] + arr[j] <= arr[k]) break;
        ans++;
      }
    }
  }

  printf("%d\n", ans);
  return 0;
}