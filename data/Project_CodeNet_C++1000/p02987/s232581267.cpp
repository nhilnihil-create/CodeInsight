#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int MOD=1000000007;

int main() {
  vector<char> a(4);
  cin >> a[0] >> a[1] >> a[2] >> a[3];
  sort(a.begin(),a.end());
  cout << (a[0]==a[1]&&a[2]==a[3]&&a[1]!=a[2]? "Yes" : "No") << endl;
  return 0;
}
