#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define all(x) (x).begin(), (x).end()
#define fsp(x) cout << fixed << setprecision(x)
#define endl '\n'
const ll inf = LLONG_MAX;
const long double pi = M_PI;
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

//公約数列挙
//昇順
vll div(ll n) {
  vll vec(1, 1);
  for (ll i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) vec.push_back(i);
  }
  if (sqrt(n) == (ll)sqrt(n)) {
    for (ll i = vec.size() - 2; i >= 0; i--) vec.push_back(n / vec[i]);
  }
  else {
    for (ll i = vec.size() - 1; i >= 0; i--) vec.push_back(n / vec[i]);
  }
  return vec;
}

vll comdiv(ll a, ll b) {
  if (a > b) swap(a, b);
  vll vec1 = div(a);
  vll vec2(0);
  for (ll i = 0; i < vec1.size(); i++) {
    if (b % vec1[i] == 0) vec2.push_back(vec1[i]);
  }
  return vec2;
}

//素数判定
bool is_prime(ll n) {
  if (n == 1) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  for (ll i = 3; i <= sqrt(n); i += 2) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  ll a, b;
  cin >> a >> b;
  vll v = comdiv(a, b);
  ll ans = 0;
  for (ll i = 0; i < v.size(); i++) {
    if (is_prime(v[i])) ans++;
  }
  cout << ans + 1 << endl;
}