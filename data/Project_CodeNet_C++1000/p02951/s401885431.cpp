#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
int main() {
  int a,b,c;
  cin >> a >> b >> c;
  if(c-(a-b) <0) cout << 0 << endl; 
  else cout << c-(a-b) << endl;
}
