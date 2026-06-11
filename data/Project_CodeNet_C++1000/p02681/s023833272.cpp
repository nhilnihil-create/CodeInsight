#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const int MOD = 1000000007;
using Graph = vector<vector<int>>;
using ping = pair<ll, ll>;

int main() {
  string S, T;
  cin >> S >> T;
  bool check = true;
  if (S.size() + 1 != T.size()) check = false;
  for (int i = 0; i < S.size(); i++){
    if (S[i] != T[i]) check = false;
  }
  if(check){
    cout << "Yes" << endl;
  }
  else{
      cout << "No" << endl;
  }
  return 0;
}