#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

int main()
{
  int n;
  cin >> n;
  long f[n + 1];
  for (int i = 1; i <= n; i++) f[i] = 1;
  long x = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      f[j]++;
    }
    x += f[i] * i;
  }
  cout << x << endl;
  return 0;
}
