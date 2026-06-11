
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
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
  ll N;
  cin >> N;
  vector<ll> A(N+1);
  vector<ll> NUM(N+1);

  loop(1, N+1, i) {
    cin >> A[i];
  }
  int cnt = 0;
  for (int i=N; i >= 1; i--) {
    int k = 0;
    for (int j=i; j<=N; j+=i) {
      if (NUM[j] == 1) {
        k++;
      }
    }
    if (k%2 != A[i]) {
      NUM[i] = 1;
      cnt++;
    }
  }
  if (cnt == 0) {
    print(0);
    return 0;
  }
  print(cnt);
  bool flag = true;
  for (int i=1; i<=N; i++) {
    if (NUM[i] == 1) {
      if (flag) {
        cout << i;
        flag = false;
      } else {
        cout << " " << i;
      }
    }
  }
  cout << "\n";
  return 0;
}