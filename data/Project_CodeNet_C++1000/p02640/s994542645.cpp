#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int x,y;
  cin >> x >> y;
  if(x*2<=y&&x*4>=y&&y%2==0)cout << "Yes" << endl;
  else cout << "No" << endl;
}