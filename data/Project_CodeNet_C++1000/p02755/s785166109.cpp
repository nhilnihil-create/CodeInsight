#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  int A, B;
  cin >> A >> B;
  rep(i, 1250){
    if (((i+1) * 8 / 100) == A && ((i+1) * 10 / 100) == B){
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
