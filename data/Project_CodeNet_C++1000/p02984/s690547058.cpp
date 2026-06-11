#include<bits/stdc++.h>
using namespace std;

int N;
int A[100000];

signed main() {
  cin >> N;
  int sum = 0;
  for(int i=0; i<N; i++) cin >> A[i];
  for(int i=0; i<N; i++) sum += A[i];

  int x = sum;
  for(int i=1; i<N; i+=2) x -= A[i]*2;
  cout << x;
  for(int i=1; i<N; i++) {
    x = A[i-1] * 2 - x;
    cout << " " << x;
  }
  cout << endl;
}
