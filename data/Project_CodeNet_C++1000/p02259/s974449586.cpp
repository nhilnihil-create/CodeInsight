#include <iostream>
using namespace std;

int A[100], N;

int bubbleSort();
void trace();

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) { cin >> A[i]; }
  
  int count = bubbleSort();
  trace();
  cout << count << "\n";
  
  return 0;
}

// sort
int bubbleSort() {
  unsigned char flag = 1;
  int count = 0;
  while (flag) {
    flag = 0;
    for (int j = N - 1; j > 0; --j) {
      if (A[j] < A[j - 1]) {
        flag = 1; count++;
        int t = A[j];
        A[j] = A[j - 1];
        A[j - 1] = t;
      }
    }
  }
  return count;
}

// print
void trace() {
  for (int i = 0; i < N; ++i) {
    if (i) { cout << " "; }
    cout << A[i];
  }
  cout << "\n";
}