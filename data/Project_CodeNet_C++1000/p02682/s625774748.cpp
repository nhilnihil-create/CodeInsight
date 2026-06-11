#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int A, B, C, K;
  cin >> A >> B >> C >> K;
  
  int ans = 0;
  
  
   for(int i = 0; i < K; i++) {
     if(i < A) ans++;
     else if(i < A + B) continue;
     else ans--;
   }
  
  cout << ans << endl;
}