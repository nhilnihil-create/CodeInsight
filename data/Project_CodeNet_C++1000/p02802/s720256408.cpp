// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

int main() {
  int a, b; cin >> a >> b;
  vector<int> P(b);
  vector<string> S(b);
  loop(i,0,b) cin >> P[i] >> S[i];
  loop(i,0,b) P[i]--;
  
  vector<int> C(a, 0);
  vector<bool> AC(a, false);
  int ac = 0;
  
  loop(i,0,b) {
    int p = P[i];
    if (AC[p]) continue; // AC済みはペナルティ増加無し
    if (S[i] == "WA") {
      C[p]++;
    } else {
      ac++;
      AC[p] = true;
    }
  }
  
  ll cnt = 0;
  loop(i,0,a) {
    if (!AC[i]) continue;
    cnt += C[i];
  }
  cout << ac << " " << cnt << endl;
  return 0;
}
