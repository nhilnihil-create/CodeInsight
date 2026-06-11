#include <bits/stdc++.h>
#define lp(n) for(int i = 0; i < n; i++)
#define lpp(i, n) for(int i = 0; i < n; i++)
int partition(int A[], int p, int r) {
  int t;
  int x = A[r];
  int i = p - 1;
  for(int j = p; j < r; j++) {
    if(A[j] <= x) {
      i++;
      t = A[i];
      A[i] =  A[j];
      A[j] = t;
    }
  }
  t = A[i+1];
  A[i+1] =  A[r];
  A[r] = t;
  return i+1;
}
using namespace std;
int main() {
  int n;
  int c;
  int *A;
  cin >> n;
  A = (int *)malloc(n *sizeof(int));
  lp(n) cin >> A[i];
  c = partition(A, 0, n-1);
  lp(c) cout << A[i] << " ";
  cout<< '[' << A[c] << "] ";
  for(int i = c+1; i < n-1; i++) cout << A[i] << " ";
  cout << A[n-1] << endl;
  return 0;
}


