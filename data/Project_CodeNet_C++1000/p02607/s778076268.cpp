#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int ans = 0;
  
  for (int i = 1; i <= N; i++) {
    int x;
    cin >> x;
    
    if (x % 2 && i % 2) ans++;
  }
  
  cout << ans << endl;
}