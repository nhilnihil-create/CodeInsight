#include <iostream>
#define rep(i, n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    int a;
    cin >> a;
    if (i % 2 == 1 && a % 2 == 1) ans++;
  }
  
  cout << ans;
}