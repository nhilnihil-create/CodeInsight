#include <iostream>
#include <cmath>

using namespace std;

int cnt;

void InsertionSort(int A[], int n, int g) {
  for(int i = g; i < n; i++) {
    int v = A[i];
    int j = i - g;
    while(j >= 0 && A[j] > v) {
      A[j + g] = A[j];
      j -= g;
      cnt++;
    }
    A[j + g] = v;
  }
}

void ShellSort(int A[], int n) {
  int m = log2(n) + 1;
  int G[20], j = 1;
  for(int i = m - 1; i >= 0; i--) {
    G[i] = j;
    j *= 2;
  }

  for(int i = 0; i < m; i++) {
    InsertionSort(A,n,G[i]);
  }

  cout << m << endl;
  for(int i = 0; i < m; i++) {
    if(i == m - 1) {
      cout << G[i] << endl;
    } else {
      cout << G[i] << " ";
    }
  }
  cout << cnt << endl;
  for(int i = 0; i < n; i++) {
    cout << A[i] << endl;
  }
}

int main() {
  int n;
  cin >> n;
  static int A[1000000];
  for(int i = 0; i < n; i++) {
    cin >> A[i];
  }

  ShellSort(A, n);

  return 0;
}
