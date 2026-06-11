#include <iostream>
#include <array>
#include <vector>
#include <cmath>

using namespace std;

static void printArray(int A[], int N) {
  for (int i = 0; i < N; i++) {
    cout << A[i] << endl;
  }
}

static void inputArray(int A[], int N) {
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
}

static int insersionSort(int A[], int N, int g) {
  int v, j, count = 0;
  for (int i = g; i < N; i++) {
    v = A[i];
    j = i - g;
    while (j >= 0 && A[j] > v) {
      A[j + g] = A[j];
      j = j - g;
      count++;
    }
    A[j + g] = v;
  }
  return count;
}

#include <cstdio>

static int shellSort(array<int, 1000000>& A,  int N) {
  array<int, 1000000> sortArray(A);
  int g = 1, startedIndex = 0, count = 0;
  vector<int> G = { 1 };
  for (; g < N; ) {
    G.push_back(g);
    g = 3 * g;
  }
  for (g = G.size() - 1;  g >= 0; g--) {
    if (G[g] * 2 > N) {
      continue;
    }
    if (startedIndex == 0) {
      startedIndex = g;
    }
    count += insersionSort(sortArray.data(), N, G[g]);
/* 
    if (count > pow(N, 1.5f)) {
      sortArray = A;
      continue;
    } 
*/
  }

  cout << startedIndex + 1 << endl;
  for (int i = startedIndex; i >= 0; i--) {
    cout << G[i];
    cout << ' ';
  }
  cout << endl;
  cout << count << endl;
  A = sortArray;
  return count;
}
  
int main() {
  int N;
  cin >> N;

  array<int, 1000000> A;
  inputArray(A.data(), N);

//  printArray(A.data(), N);

  shellSort(A, N);

  printArray(A.data(), N);
  
  return 0;
}

