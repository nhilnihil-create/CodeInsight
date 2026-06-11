#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;
vector<int> insertionSort(vector<int> A, int n, int g) {
  for (int i = g; i < n; i++) {
    int v = A[i];
    int j = i - g;
    while (j >= 0 && A[j] > v) {
      A[j+g] = A[j];
      j = j - g;
      cnt++;
    }
    A[j+g] = v;
  }
  return A;
}

vector<int> shellSort (vector<int> A, int n) {
  vector<int> G;
  int tmp = n;
  while (tmp >= 1) {
    tmp /= 2;
    G.push_back(tmp);
  }
  
  int m = G.size();
  for (int i = 0; i < m; i++) {
    A = insertionSort(A, n, G[i]);
  }

  cout << m << endl;
  for (int i = 0; i < m; i++) {
    cout << G[i];
    if (i != m-1) cout << ' ';
    else cout << endl;
  }
  cout << cnt << endl;
  return A;
}

int main(int argc, char* argv[]) {
  int n; cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  vector<int> ans = shellSort(A, n);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
  return 0;
}