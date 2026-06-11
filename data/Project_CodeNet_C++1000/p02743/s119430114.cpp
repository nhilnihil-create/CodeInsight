#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  ll a,b,c;
  cin >> a >> b >> c;

  if(c - a - b <= 0) {
    cout << "No" << '\n';
    return 0;
  }

  ll left = 4LL * a * b;
  ll right = (c - a - b) * (c - a - b);
  if(left < right) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
}
