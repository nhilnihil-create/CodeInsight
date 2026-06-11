#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int h,n;
  cin >> h >> n;
  vi a(n);
  rep(i,n) cin >> a[i];
  ll sum = 0;
  rep(i,n) sum += a[i];
  if(sum >= h) cout << "Yes" << endl;
  else cout << "No" << endl;
}
