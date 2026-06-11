#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int A, B;
  cin >> A >> B;
  
  int max_k = 1000000000;

  rep(i, max_k){
    if (abs(A - i) == abs(B - i)){
      cout << i << endl;
      return 0;
    }
  }

  cout << "IMPOSSIBLE" << endl;
}