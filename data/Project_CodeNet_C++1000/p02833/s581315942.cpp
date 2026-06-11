#include <iostream>
using namespace std;
int main() {
  long long N, ans{};
  cin >> N;
  if (N % 2) ans = 0;
  else {
    N /= 2;
    while (N) ans += (N /= 5);
  }
  cout << ans << endl;
}
