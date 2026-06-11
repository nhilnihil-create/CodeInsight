#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
int n;
cin >> n;
vector<int> a(n+1);
vector<int> b(n);
rep(i,n+1) cin >> a.at(i);
rep(i,n) cin >> b.at(i);
ll ans = 0;
rep(i,n){
  int left = min(a.at(i),b.at(i));
  ans += left;
  a.at(i) -= left;
  b.at(i) -= left;

  int right = min(a.at(i+1),b.at(i));
  ans += right;
  a.at(i+1) -= right;
  b.at(i) -= right;
}
cout << ans << endl;
}
