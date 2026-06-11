#include <iostream>
using namespace std;

int main() {
  int n, k, a; cin >> n >> k;
  int res{0};
  for (int i = 0; i < n; ++i) {
   	cin >> a;
   	if (a >= k) {
      res++;
    }
  }
  cout << res << endl;
}