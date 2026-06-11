#include <iostream>
using namespace std;

int N, *A;
int cnt;

void isort(int *A, int n, int g) {
  for (auto i = g; i < n; i++) {
    auto v = A[i];
    int j;
    for (j = i - g; j >= 0 && A[j] > v; j -= g) {
      A[j+g] = A[j];
      cnt++;
    }
    A[j+g] = v;
  }
}

void shsort(int *A, int n) {
  cnt = 0;
  int m = 0;
  int G[] = {1, 4, 13, 40, 121, 364, 1093, 3280, 9841, 29524, 88573, 265720, 797161};
  for (; G[m] <= n; m++);
  cout << m << endl;
  for (auto i = m - 1; i >= 0; i--) {
    if (i != m - 1) cout << " ";
    cout << G[i];
    isort(A, n, G[i]);
  }
  cout << endl;
  cout << cnt << endl;
}

int main(void){
  cin >> N;
  A = new int[N];
  for (auto i = 0; i < N; i++) cin >> A[i];
  
  shsort(A, N);
  
  for (int i = 0; i < N; i++) cout << A[i] << endl;
  
  delete[] A;
  
  return 0;
}