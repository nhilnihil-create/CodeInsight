#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int MOD = 1000000007;

int main() {
  string S; cin >> S;
  
  if (S[S.size()-1] == 's') S = S + "es";
  else S = S + "s";
  
  cout << S << endl;  
}