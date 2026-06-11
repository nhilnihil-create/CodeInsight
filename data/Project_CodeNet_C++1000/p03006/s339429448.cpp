#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define all(x) (x).begin(), (x).end()
ll inf = LLONG_MAX;
long double pi = M_PI;
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
  ll n;
  cin >> n;

  vector<vll> ball(n, vll(2));
  for (ll i = 0; i < n; i++) cin >> ball[i][0] >> ball[i][1];

  vector<vll> dxdy(0);
  for (ll i = 0; i < n - 1; i++) {
    for (ll j = i + 1; j < n; j++) {
      vll v = {ball[j][0] - ball[i][0], ball[j][1] - ball[i][1]};
      vll w = {- ball[j][0] + ball[i][0], - ball[j][1] + ball[i][1]};
      dxdy.push_back(v);
      dxdy.push_back(w);
    }
  }
  sort(all(dxdy));

  ll subans = 0, m = dxdy.size();
  for (ll i = 0; i < m; i++) {
    ll cnt = 0;
    vll v = dxdy[i];
    while (i < m && dxdy[i] == v) {
      cnt++;
      i++;
    }
    i--;
    subans = max(subans, cnt);
  }

  cout << n - subans << endl;
}