#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  string S,T,U;
  ll A = 0, B = 0;
  map<string,ll> mp;
  cin >> S >> T >> A >> B >> U;
  mp[S] = A;
  mp[T] = B;
  mp[U]--;
  cout << mp[S] << " " << mp[T];
}
  