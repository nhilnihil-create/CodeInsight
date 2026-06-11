#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n;
  cin >> n;
  vector<P> a(n);
  rep(i,n) {
    int x, l;
    cin >> x >> l;
    a[i] = make_pair(x+l,x-l);
  }
  sort(rng(a));
  int cnt = 0;
  int cur = -1001001001;
  for(int i = 0; i < n; i++) {
      if(cur<=a[i].second) {
        cnt++;
        cur = a[i].first;
      }
  }
  cout << cnt << endl;
  return 0;
}