#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string S;
  int Q;
  cin >> S >> Q;
  
  int cnt = 0;
  string R = "";
  while (Q--) {
    int T;
    cin >> T;
    if (T == 1)
    {
      cnt++;
    } else
    {
      int F;
      char C;
      cin >> F >> C;
      if ((F == 1 && cnt % 2 == 0) || (F == 2 && cnt % 2 == 1)) {
        R += C;
      } else
      {
        S += C;
      }      
    }  
  }

  reverse(R.begin(), R.end());
  S = R + S;
  if (cnt % 2 == 1)
  {
    reverse(S.begin(), S.end());
  }
  cout << S << endl;
  return 0;
}
