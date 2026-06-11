#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int k,a,b;
  string ans = "NG";
  cin >> k >> a >> b;
  for(int i = a; i <=b; i++){
    if(i % k == 0) ans = "OK";
  }
  cout << ans << endl;
}