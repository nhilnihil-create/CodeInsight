#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {
  string S;cin >> S;
  bool ans = false;
  if(S[0] == S[1] && S[2] == S[3] && S[0] != S[2]) ans = true;
  if(S[0] == S[2] && S[1] == S[3] && S[0] != S[1]) ans = true;
  if(S[0] == S[3] && S[1] == S[2] && S[0] != S[1]) ans = true;
  
  if(ans) puts("Yes");
  else puts("No");

	return 0;
}

