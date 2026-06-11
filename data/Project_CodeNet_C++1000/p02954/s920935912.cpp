

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

struct Data {
  int r, l, k;
};

int main() {
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
  string S;
  cin >> S;
  int N = S.length();
  vector<Data> A(N);

  loop(0, N, i) {
    if (S[i] == 'R') {
      A[i].k = 0;
    } else {
      A[i].k = 1;
    }
  }
  A[0].r = 0;
  for (int i=0; i<N; i++) {
    if (S[i] == 'R') {
      A[i].r = i;
    } else {
      A[i].r = A[i-1].r;
    }
  }
  A[N-1].l = N-1;
  for (int i=N-2; i>=0; i--) {
    if (S[i] == 'L') {
      A[i].l = i;
    } else {
      A[i].l = A[i+1].l;
    }
  }
  vector<int> COUNT(N);
  loop(0, N, i) {
    if (A[i].k == 0) {
      int d = A[i].l - i;
      if (d%2 == 0) {
        COUNT[A[i].l]++;
      } else {
        COUNT[A[i].l-1]++;
      }
    } else {
      int d = i - A[i].r;
      if (d%2 == 0) {
        COUNT[A[i].r]++;
      } else {
        COUNT[A[i].r+1]++;
      }
    }
  }
  loop(0, N, i) {
    if (i == N-1) {
      cout << COUNT[i] << endl;
    } else {
      cout << COUNT[i] << " ";
    }
  }
}