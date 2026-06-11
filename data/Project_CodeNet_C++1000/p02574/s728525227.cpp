#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 1000005

int nums[MAX_SIZE];
vector<bool> check(MAX_SIZE, false);

int main() {
  int n;
  scanf("%d", &n);

  memset(nums, 0, sizeof(nums));
  int max_a = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    nums[x]++;
    if (x > max_a) {
      max_a = x;
    }
  }

  // 0 for pair-wise, 1 for set-wise, 2 for not
  int ans = 0;

  for (int pointer = 2; pointer <= max_a;) {
    int count = 0;
    for (int i = pointer; i <= max_a; i += pointer) {
      count += nums[i];
      check[i] = true;
    }
    
    if (count == n) {
      ans = 2;
      break;
    } else if (count > 1){
      ans = 1;
    }

    while(pointer <= max_a && check[pointer]) {
      pointer++;
    }
    
  }

  const char *ans_str[] = {"pairwise coprime", "setwise coprime", "not coprime"};
  printf("%s\n", ans_str[ans]);
  return 0;
}