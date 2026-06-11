#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int root(vector<int> &parent, int idx) { 
  if (parent[idx] < 0)
    return idx;
  return parent[idx] = root(parent, parent[idx]);
}

long long N, M;
int main() { 
  cin >> N >> M;
  vector<int> parent(N, -1);
  for (int i = 0; i < M; ++i) {
    int A, B;
    cin >> A >> B;
    int root_a = root(parent, --A);
    int root_b = root(parent, --B);
    if (root_a != root_b) {
      parent[root_a] += parent[root_b];
      parent[root_b] = root_a;
    }
  }
  int result = 0;
  for (int i = 0; i < N; ++i) {
    result = max(result, -parent[i]);
  }
  cout << result << endl;
}
