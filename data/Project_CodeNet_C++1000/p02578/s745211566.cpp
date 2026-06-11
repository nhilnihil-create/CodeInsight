#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  long long ans = 0;
  int MaxH = 0;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    MaxH = max(MaxH, a);
    ans += MaxH - a;
  }
  
  cout << ans;
}