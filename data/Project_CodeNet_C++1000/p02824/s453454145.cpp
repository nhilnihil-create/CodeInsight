#include<bits/stdc++.h>
using namespace std;

int main() {
  long long N,M,V,P;
  cin >> N >> M >> V >> P;
  vector<long long> A(N);
  for (int i=0; i<N; i++) {
    cin >> A[i];
  }
  sort(A.begin(),A.end());
  reverse(A.begin(),A.end());
  
  long long OK = P-1;
  long long NG = N;
  long long unvoted,mid,minscore;
  
  while(NG - OK > 1) {
    mid = (NG+OK)/2;
    unvoted = (V-P) * M;
    minscore = A[mid] + M;
    for (int i=P-1; i<N; i++) {
      if (i == mid) continue;
      if (A[i] > minscore) {
        unvoted = 1;
        break;
      }
      unvoted -= min(M,minscore - A[i]);
    }
    if (unvoted <= 0) {
      OK = mid;
    }
    else NG = mid;
  }
  
  cout << OK+1 << endl;
}
