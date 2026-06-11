#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
const ll MOD = 1000000007;
// const ll INF = 1000000000000000000LL;

int main() {
  // reverseはひっくり返して変数にいれることができないので
  // コピーをつくってやることで対処した
  string s;
  cin >> s;
  int n = s.size();
  bool can = true;
  string rs1,rs2,rs3;
  string s2 = s.substr(0,(n-1)/2);
  // cout << s2 << endl;
  string s3 = s.substr((n+3)/2-1,n-1);
  // cout << s3 << endl;
  rs1 = s;
  rs2 = s2;
  rs3 = s3;
  reverse(s.begin(),s.end());
  reverse(s2.begin(),s2.end());
  reverse(s3.begin(),s3.end());
  if(s!=rs1) can = false;
  if(s2!=rs2) can = false;
  if(s3!=rs3) can = false;
  if(can) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
