#include <cstdio>
int K, X;

int main() {
  scanf(" %d%d", &K, &X);
  puts((K * 500 >= X) ? "Yes" : "No");
  return 0;
}