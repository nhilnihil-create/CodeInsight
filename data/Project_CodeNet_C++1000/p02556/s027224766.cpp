#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  vector<int> a(n);
  vector<int> b(n);
  rep(i,n){
    cin >> x[i] >> y[i];
    a[i]=x[i]+y[i];
    b[i]=x[i]-y[i];
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  int res = a[a.size()-1]-a[0];
  res = max(res,b[b.size()-1]-b[0]);
  cout << res << endl;
  return 0;
}
