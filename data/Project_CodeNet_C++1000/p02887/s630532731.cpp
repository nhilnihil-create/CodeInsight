#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,ans=0;
  string S;
  cin >> N >> S;

  for(int i=0; i<N; i++) {
    if(S[i] != S[i+1]) ans++;
  }
  cout << ans << endl;
}