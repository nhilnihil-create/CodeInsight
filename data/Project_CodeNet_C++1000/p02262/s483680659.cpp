#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cnt;

void print(vector<int> A) {
  for (int i = 0; i < A.size(); ++i) {
    cout << ( (i) ? " " : "" ) << A[i];
  }
  cout << endl;
}

vector<int> insertionSort(vector<int> A, int n, int g) {
  for (int i = g; i < n; ++i) {
    int v = A[i];
    int j = i - g;
    while (j >= 0 && A[j] > v) {
      A[j + g] = A[j];
      j -= g;
      ++cnt;
    }
    A[j + g] = v;
  }
  return A;
}

vector<int> shellSort(vector<int> A, int n) {
  cnt = 0;
  vector<int> G; {
    for (int h = 1; ; ) {
      if (h > n) break;
      G.push_back(h);
      h = 3 * h + 1;
    }
    cout << G.size() << endl;
    reverse(begin(G), end(G));
    print(G);
  }
  for (int i = 0; i < G.size(); ++i) {
    A = insertionSort(A, n, G[i]);
  }
  return A;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N; { cin >> N; }
  vector<int> A(N); { for (int i = 0; i < N; ++i) cin >> A[i]; }
  A = shellSort(A, N); {
    cout << cnt << endl;
    for (auto&& x : A) cout << x << endl;
  }
  return 0;
}

