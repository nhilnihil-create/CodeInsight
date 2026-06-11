#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

int main(){ 
  string S, T; cin >> S >> T;
  int sum = 0;
  
  rep(i,3) if (S[i] == T[i]) sum++;

  cout << sum << endl;
}