#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  int N;
  cin >> N;
  int A[N];
  rep(i, N) cin >> A[i];
  bool check = true;
  rep(i, N){
    if (A[i] % 2 == 0){
      if ((A[i] % 3 == 0) || (A[i] % 5 == 0)) check *= true;
      else check *= false;
    }
  }
  if (check) cout << "APPROVED" << endl;
  else cout << "DENIED" << endl;
}
