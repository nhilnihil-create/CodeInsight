#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n, x, l;
  cin >> n;
  vector<pair<int, int>> r(n);
  rep(i, n){
    cin >> x >> l;
    r[i] = make_pair(x+l, x-l);
  }
  sort(r.begin(), r.end());
  int c = 0, p = -1e9;
  rep(i, n){
    if (p <= r[i].second){
      c++;
      p = r[i].first;
    }
  }
  cout << c << endl;;
  return 0;
}
