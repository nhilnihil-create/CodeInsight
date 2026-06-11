#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  int N;
  string S;
  cin >> N >> S;
  int ans = 0;
  rep(i, N-2){
    string T;
    rep(j, 3) T += S[i+j];
    if (T == "ABC") ans++;
  }
  cout << ans << endl;
}
