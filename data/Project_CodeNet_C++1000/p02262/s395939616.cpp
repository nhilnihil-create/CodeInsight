#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000000;
long long CNT = 0;

void InsertionSort(int* A, int n, int g) {
  for (int i = g; i < n; i++) {
    int v = A[i];
    int j = i - g;
    while (j >= 0 && A[j] > v) {
      A[j + g] = A[j];
      j = j - g;
      CNT++;
    }
    A[j + g] = v;
  }
}

void ShellSort(int* A, int n) {
  int cnt = 0;
  vector<int> G;
  int h = 1;
  while (true) {
    if (h > n) break;
    G.push_back(h);
    h = 3 * h + 1;
  }
  reverse(G.begin(), G.end());

  cout << G.size() << endl;
  for (int i = 0; i < G.size() - 1; i++)
    cout << G[i] << " ";
  cout << G[G.size() - 1] << endl;
  for (int i = 0; i < G.size(); i++)
    InsertionSort(A, n, G[i]);
  cout << CNT << endl;

  for (int i = 0; i < n; i++)
    cout << A[i] << endl;
}

int main() {
  int n;
  int A[MAX];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];

  ShellSort(A, n);

  return 0;
}
