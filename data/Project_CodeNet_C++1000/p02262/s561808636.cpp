#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int A[n];
  for (int i=0; i<n; i++) {
    cin >> A[i];
  }
  vector<int> G;
  for (int h=1; ; ) {
    if (h>n) {
      break;
    }
    G.push_back(h);
    h=3*h+1;
  }
  long long cnt=0;
  for (int i=G.size()-1; i>=0; i--) {
    for (int j=G[i]; j<n; j++) {
      int v=A[j];
      int k=j-G[i];
      while (k>=0 && A[k]>v) {
        A[k+G[i]]=A[k];
        k-=G[i];
        cnt++;
      }
      A[k+G[i]]=v;
    }
  }
  printf("%d\n", G.size());
  for (int i=G.size()-1; i>=0; i--) {
    printf("%d", G[i]);
    if (i) {
      printf(" ");
    }
  }
  printf("\n");
  printf("%lld\n", cnt);
  for (int i=0; i<n; i++) {
    printf("%d\n",A[i]);
  }
  return 0;
}