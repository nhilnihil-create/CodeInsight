#include<bits/stdc++.h>
using namespace std;
#define int long long

int N, K;
int A[200000];
int F[200000];

bool ok(int score) {
  int k = 0;
  for(int i=0; i<N; i++) {
    k += max(0LL, ((F[i]*A[i] - score) + (F[i]-1)) / F[i]);
  }
  return k<=K; 
}

signed main() {
  cin >> N >> K;
  for(int i=0; i<N; i++) cin >> A[i];
  for(int i=0; i<N; i++) cin >> F[i];

  sort(A, A+N);
  sort(F, F+N, greater<int>());

  int l=0, r = 0;
  for(int i=0; i<N; i++) r = max(r, A[i]*F[i]);
  while (r-l>1) {
    int m = l + (r-l)/2;
    if(ok(m)) r=m;
    else      l=m;
  }
  if(ok(l)) r = l;
  cout << r << endl;
}
