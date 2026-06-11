#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
ll solver(int N, int K, string S) { /*
   while (K >= 0) {
     int l = 0, r = S.size() - 1;
     while (S[l] == 'L') l++;
     while (S[r] == 'R') r--;
     if (r - l >= 0) break;
     K--;
     for(int l=i;i<=r;i++){

     }
   }*/
  ll ans = 0;
  REP(i, S.size()) {
    if (i != 0 && S[i] == 'L') {
      if (S[i - 1] == 'L') ans++;
    } else if (i != S.size() - 1 && S[i] == 'R') {
      if (S[i + 1] == 'R') ans++;
    }
  }
  ans += 2 * K;
  if (ans >= S.size() - 1) ans = S.size() - 1;
  return ans;
}
int main() {
  int N, K;
  string S;
  cin >> N >> K >> S;
  cout << solver(N, K, S) << endl;
}