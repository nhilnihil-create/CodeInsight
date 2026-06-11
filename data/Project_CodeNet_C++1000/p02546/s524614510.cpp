#include <bits/stdc++.h>
using namespace std;

int main() {
  char str[1010];
  scanf("%s", str + 1);
  int len = strlen(str + 1);
  if (str[len] != 's')
    printf("%ss\n", str + 1);
  else
    printf("%ses\n", str + 1);
  return 0;
}