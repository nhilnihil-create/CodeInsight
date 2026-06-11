#include "bits/stdc++.h"
#define F first
#define S second
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll h = 0, a = 0;
  cin >> h >> a;
  if (h % a == 0)
    cout << h / a;
  else
    cout << h / a + 1;
}

