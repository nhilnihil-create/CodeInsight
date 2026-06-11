#include <bits/stdc++.h>

#define loop(s, e, i) for (int i=s; i<e; ++i)
#define print(s) cout << s << endl;
using namespace std;
using ll = long long;

/*
浮動小数点の入力
cout << fixed << setprecision(9) << endl;
*/

ll gcd(ll a, ll b) {
  if (a < b) {
    return gcd(b, a);
  }
  while(b != 0) {
    ll tmp = b;
    b = a % b;
    a = tmp;
  }
  return a;
}

int main() {
  ll N;
  cin >> N;
  vector<pair<ll, ll>> A(N);
  loop(0, N, i) {
    ll a, b;
    cin >> a >> b;
    A[i] = make_pair(b, a);
  }
  sort(A.begin(), A.end());

  ll now = 0;
  bool result = true;
  loop(0, N, i) {
    now += A[i].second;
    if (now > A[i].first) {
      result = false;
      break;
    }
  }
  if (result) {
    print("Yes");
  } else{
    print("No");
  }
  
}