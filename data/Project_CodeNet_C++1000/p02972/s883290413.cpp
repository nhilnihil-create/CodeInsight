#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int a[N+1];
  for (int i = 1; i < N+1; i++) cin >> a[i];
  
  int ans[N+1] = {0};
  int count = 0;
  
  for (int i = N; i > 0; i--) {
    int sum = 0;
    int j = i;
    
    while(j + i <= N) {
      sum += ans[j+i];
      sum %= 2;
      j += i;
    }
    
    ans[i] = abs(sum - a[i]);
    if (ans[i]) count++;
  }
  
  cout << count << endl;
  for (int i = 1; i < N+1; i++) {
    if (ans[i]) {
      cout << i << " ";
    }
  }
  
  
}