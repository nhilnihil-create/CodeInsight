#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

string S;

bool ken (int str, int goal) {
  for (int i = str-1; i <= goal+1; i++) {
    int cnt = 0;
    while(S[i] == '.' && i <= goal+1) {
      cnt++;
      i++;
    }
    if (cnt >= 3) return true;
  }
  return false;
}

bool kenken(int str, int goal) {
  int now = str;
  for (now = str; now < goal; now++) {
    if (S[now+1] == '.') continue;
    else if (now+2 <= goal && S[now+1] == '#' && S[now+2] == '.') now++;
    else break;
  }
  return now == goal;
}

int main() { 
  int N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;
  --A; --B; --C; --D;
  cin >> S;
  bool snuke = kenken(A, C);
  bool fnuke = kenken(B, D);
  bool ok = true;
  if (C > D) ok = ken(B, D);
  if (snuke && fnuke && ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}