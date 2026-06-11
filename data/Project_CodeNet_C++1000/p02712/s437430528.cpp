#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T &a, T b) {if (a < b) {a = b;return 1;}return 0;}
template<class T> inline bool chmin(T &a, T b) {if (a > b) {a = b;return 1;}return 0;}

int main(){
  ll n;
  cin >> n;
  ll total = 0;
  for (ll i = 1; i < n+1; i++) {
    if (i % 3 == 0 || i % 5 == 0) continue;
    total += i;
  }
  cout << total << endl;
}
