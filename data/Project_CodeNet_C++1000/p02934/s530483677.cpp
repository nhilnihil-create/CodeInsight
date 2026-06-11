#include <iomanip>
#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  double a[n];
  rep(i, n) cin >> a[i];
  double sum = 0;
  rep(i, n) sum += 1 / a[i];
  cout << fixed << setprecision(10) << 1 / sum << endl;
  return 0;
}
