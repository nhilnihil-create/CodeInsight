#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define all(x) (x).begin(), (x).end()
#define endl '\n'
ll inf = LLONG_MAX;
long double pi = M_PI;
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
  ll s;
  cin >> s;

  ll weird_fish = 1e9;
  ll x1 = 0, y1 = 0;
  ll x2 = weird_fish, y2 = 1;
  ll x3, y3;

  if (s <= weird_fish) {
    x3 = s;
    y3 = 0;
  }
  else if (s % weird_fish == 0) {
    x3 = 0;
    y3 = s / weird_fish;
  }
  else {
    x3 = - (s % weird_fish - weird_fish);
    y3 = s / weird_fish + 1;
  }

  cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
}