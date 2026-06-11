#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

int main(){
  Int N, A, B;
  cin >> N >> A >> B;
  
  if ((A - B) % 2 == 0) {
	cout << abs(A-B) / 2 << endl;
    return 0;
  }
  
  else {
    Int x, y;
    x = min(A, B);
    y = max(A, B);
    
    if (x-1 <= N-y) {
      cout << x + (y-x-1) / 2 << endl;
    }
    else {
      cout << N - y + 1 + (y-x-1) / 2 << endl;
    }
  }
}
