
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int A[100001];

int partision(int p, int r) {
  int x = A[r];
  int i = p - 1;
  for (int j = p; j < r; j ++) {
    if (A[j] <= x) {
      i ++;
      swap(A[i], A[j]);
    }
  }
  swap(A[i+1], A[r]);
  return i+1;
}

int main(){
  int n;cin>>n;
  rep(i, n) cin >> A[i];
  int idx = partision(0, n-1);

  rep(i, n) {
    if (i != idx) {
      cout << A[i];
    } else {
      cout << "[" << A[i] << "]";
    }
    if (i != n-1) cout << " ";
    else cout << endl;
  }
}
