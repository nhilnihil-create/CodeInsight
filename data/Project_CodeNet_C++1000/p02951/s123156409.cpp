#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int MOD=1000000007;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << max(c-a+b,0) << endl;
}