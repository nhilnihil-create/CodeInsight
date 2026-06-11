#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int a[N];
  for (int i = 0; i < N; i++) cin >> a[i];

  int ans = 0;
  for (int i = 1; i < N-1; i++) {
    if ( (a[i-1] < a[i] && a[i] < a[i+1]) || (a[i-1] > a[i] && a[i] > a[i+1])) {
      ans++;
    }
  }
  
  cout << ans << endl;
       

        
}
