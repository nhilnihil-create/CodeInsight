#include <bits/stdc++.h>
using namespace std;

int mat[501][501];

void construct(int left, int right, int level = 1) {
  if(right - left <= 1) return;
  int mid = (left + right) / 2;
  for(int i = left; i < mid; i++) for(int j = mid; j < right; j++) mat[i][j] = mat[j][i] = level;
  construct(left, mid, level + 1);
  construct(mid, right, level + 1);
}

int main() {
  int N;
  cin >> N;
  construct(0, N);
  for(int i = 0; i < N; i++) for(int j = i + 1; j < N; j++) cout << mat[i][j] << " \n"[j + 1 == N];
  return 0;
}