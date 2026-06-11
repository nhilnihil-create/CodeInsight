#include <iostream>

using namespace std;

int main() {
  int N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;
  --A, --B, --C, --D;
  string S;
  cin >> S;
  bool cond = S.substr(A,C-A+1).find("##") == string::npos;
  cond &= S.substr(B,D-B+1).find("##") == string::npos;
  if (D < C) cond &= S.substr(B-1,D-B+3).find("...") != string::npos;
  cout << (cond ? "Yes" : "No") << endl; 
}
