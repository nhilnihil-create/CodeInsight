#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  long long ans = 0;
  int base; //最低限必要な高さ
  cin >> base;
  for (int i = 1; i < N; i++) {
    int a;
    cin >> a;
    if (base >= a) {
      ans += base - a;
    } else {
      base = a;
    }
  }
  
  cout << ans;
}