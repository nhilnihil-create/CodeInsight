#include "bits/stdc++.h"
using namespace std;

long InsertionSort(vector<int>& A, int n, int g) {
  long cnt = 0;
  for (int i = g; i < n; ++i) {
    int v = A[i];
    int j = i - g;
    while (j >= 0 && A[j] > v) {
      A[j + g] = A[j];
      j = j - g;
      ++cnt;
    }
    A[j + g] = v;
  }
  return cnt;
}

void ShellSort(vector<int>& A, int n) {
  vector<int> G; // = {1, 4, 13, 40, 121...}
  //g_n+1 = 3g_n + 1?????°????????¨????????¨O(N^1.25)??¨???????????¨????????¶????????£????????¬???????????????
  for (int i = 1; i <= n; i = 3 * i + 1) {
    G.push_back(i);
  }
  cout << G.size() << endl;  //output m
  //?????????????????????????????\?????????
  long cnt = 0;
  for (auto itr = G.crbegin(); itr != G.crend(); ++itr) {
    if (itr != G.crbegin()) cout << " "; // output[13 4 1]
    cout << *itr;
    cnt += InsertionSort(A, n, *itr);
  }
  cout << endl;
  cout << cnt << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n; //input
  vector<int> A(n);
  for (auto& a : A)
    cin >> a; //input
  ShellSort(A, n);
  for (auto& a : A)
    cout << a << endl;  //output
  //system("pause");
}