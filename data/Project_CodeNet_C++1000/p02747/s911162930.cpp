#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {
  string S; cin >> S;
  string sok = "hihihihihi";
  bool ans = false;
  if(S.size()%2 == 0 && S == sok.substr(0, S.size())) ans = true;
  



  cout << (ans ? "Yes" : "No") << endl;

	return 0;
}

