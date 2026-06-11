#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int MOD=1000000007;

int main() {
  string s, t;
  int n=0;
  cin >> s >> t;
  if(s[0]==t[0]) n++;
  if(s[1]==t[1]) n++;
  if(s[2]==t[2]) n++;

  cout << n << endl;
}
