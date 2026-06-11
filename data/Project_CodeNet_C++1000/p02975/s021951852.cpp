#include <map>
int main() {
  int N, a, x{}, n{3}, b{1};
  scanf("%d",&N);
  std::map<int, int> m;
  if (N % 3) while (scanf("%d",&a)+1) b &= !a;
  else {
    N /= 3;
    while (scanf("%d",&a)+1) if (!(++m[a] % N)) --n, x ^= a;
    b = !n && !x;
  }
  printf("%s\n", b?"Yes":"No");
}
