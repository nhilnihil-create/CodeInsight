#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
constexpr ll mod = 1e9 + 7;
#define endl '\n'
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 
  ll n;
  cin >> n;
  int d = n%10;
  if (d == 3) {
    cout << "bon" << endl;
  } else if (d <= 1 || d == 6 || d == 8) {
    cout << "pon" << endl;
  } else {
    cout << "hon" << endl;
  }

}
