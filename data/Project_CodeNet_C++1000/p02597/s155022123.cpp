#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<n;i++)
using namespace std;
 
int main() {
  int N;
  string S;
  cin >> N >> S;
  int A=0,B=0;
  rep(i,N) if (S[i]=='R') A++;
  int ans = A;
  rep(i,N) {
    if (S[i]=='W') B++;
    else A--;
    ans = min(ans,max(A,B));
  }
  cout << ans << endl;
}