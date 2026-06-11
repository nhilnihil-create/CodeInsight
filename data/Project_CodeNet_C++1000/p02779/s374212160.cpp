#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  set<int> a;
  bool ok = true;
  rep(i, n) {
    int at;
    cin >> at;
    if(a.count(at) == 0) a.insert(at);
    else ok = false;
  }
    
  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}