#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<char> C(N);
  int rc = 0;
  for (int i = 0; i < N; i++) {
    cin >> C[i];
    if (C[i] == 'R') rc++;
  }
  
  int ans = 0;
  for (int i = 0; i < rc; i++) {
    if (C[i] == 'W') ans++;
  }
   
  cout << ans;
 
}
