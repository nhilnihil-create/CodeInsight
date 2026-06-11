#include <bits/stdc++.h>

using namespace std;

const int SIZE_LIMIT = 2e5+5;
char arr[SIZE_LIMIT];

int main() {
  memset(arr, 0, sizeof(arr));

  scanf("%s", arr);
  int sum = 0;
  for (int i = 0; i < strlen(arr); ++i) {
    sum += arr[i] - '0';
  }
  const char* ans[2] = {"No", "Yes"};
  printf("%s\n", ans[sum%9==0]);
  return 0;
}