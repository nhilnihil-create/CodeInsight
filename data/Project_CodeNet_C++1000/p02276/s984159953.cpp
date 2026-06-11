#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n)    FOR(i, 0, n)
#define pb           push_back
#define all(a)       (a).begin(), (a).end()
#define UNIQUE(v)    v.erase(unique(all(v)), v.end());
#define fill(a, x)   memset(a, x, sizeof(a))
#define zero(a)      fill(a, 0)
#define minus(a)     fill(a, -1)
#define dbg(x)       cout << #x "=" << x << endl
// #define MAX          100000
// int A[MAX], n;

int partition(int *A, int p, int r) {
  int x = A[r];
  int i = p - 1;
  for (int j = p; j < r; j++) {
    if (A[j] <= x) {
      i++;
      swap(A[i], A[j]);
    }
  }
  i++;
  swap(A[i], A[r]);
  return i;
}

signed main() {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int A[n];

  int c = 0;
  while (c < n) {
    int tmp;
    cin >> tmp;
    A[c] = tmp;
    c++;
  }

  int k = partition(A, 0, n - 1);

  // for (int i = 0; i < n; i++) {
  //   if (i)
  //     cout << " ";
  //   if (i == k)
  //     cout << "[";
  //   cout << A[i];
  //   if (i == k)
  //     cout << "]";
  //   if (i == n - 1) {
  //     cout << endl;
  //   }
  // }

  // rep(i, n) {
  //   if (i != 0) {
  //     cout << " ";
  //   }
  //   if (i == k) {
  //     cout << "[" << A[i] << "]";
  //   } else {
  //     cout << A[i];
  //   }
  //   if (i == n - 1) {
  //     cout << endl;
  //   }
  // }

  rep(i, n) {
    if (i == k) {
      cout << "[" << A[i] << "] ";
    } else if (i == n - 1) {
      cout << A[i] << endl;
    } else {
      cout << A[i] << " ";
    }
  }

  return 0;
}

