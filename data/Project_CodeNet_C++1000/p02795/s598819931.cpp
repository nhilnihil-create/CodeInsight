#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int h,w,n;
  cin >> h >> w >> n;
  int ans = n/max(h,w);
  if(n%max(h,w) != 0) ans++;
  cout << ans << endl;
}