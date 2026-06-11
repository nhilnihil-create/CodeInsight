#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C;
  cin >> A >> B >> C;
  bool ans = false;
  if(A == B && A!= C || B == C && B != A || C == A && C != B) ans = true;
  puts(ans ? "Yes":"No");
}
