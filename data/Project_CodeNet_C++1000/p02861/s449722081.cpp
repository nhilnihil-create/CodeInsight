#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long int;

int main() {
  int N;
  cin >> N;

  vector<pair<int, int>> C(N);
  rep(i, N) cin >> C[i].first >> C[i].second;

  vector<int> array;
  rep(i, N) array.push_back(i);

  double dist = 0;
  int count = 0;
  do {
    for (int i = 0; i < N - 1; i++) {
      dist += pow(pow(C[array[i]].first - C[array[i + 1]].first, 2) +
              pow(C[array[i]].second - C[array[i + 1]].second, 2),
          0.5);
    }
    count++;
  } while (next_permutation(array.begin(), array.end()));
  cout << setprecision(10) << dist / (double)count << endl;
}