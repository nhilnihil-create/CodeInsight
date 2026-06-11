#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int64_t N, A, B; cin >> N >> A >> B;
  
  int64_t loseAll = N - A; int64_t winAll = B - 1;
  
  int64_t minAll = min(loseAll, winAll);
  
  int64_t backFrom1 = A + (B - A - 1) / 2;
  
  int64_t backFromN = N - B + 1 + (B - A - 1) / 2;
  
  int64_t minBack = min(backFrom1, backFromN);
  
  if ((B - A) % 2 == 0) {
    
    int64_t center = (B - A) / 2;
    
    cout << center << endl;
    
  }
  
  else cout << min(minAll, minBack) << endl;
  
}