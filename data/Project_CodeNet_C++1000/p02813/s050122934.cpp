#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long int;

int main() {
  int N;
  cin >> N;

  vector<int> array1;
  vector<int> array2;
  for (int i = 1; i <= N; i++) {
    array1.push_back(i);
    array2.push_back(i);
  }

  vector<int> P(N, 0);
  vector<int> Q(N, 0);
  rep(i, N) cin >> P[i];
  rep(i, N) cin >> Q[i];

  int count = 0;
  int a = 0;
  do {
    if (P == array1) {
      a = count;
    } else {
      count++;
    }
  } while (next_permutation(array1.begin(), array1.end()));

  count = 0;
  int b = 0;
  do {
    if (Q == array2) {
      b = count;
    } else {
      count++;
    }
  } while (next_permutation(array2.begin(), array2.end()));

  cout << abs(a-b) << endl;
}