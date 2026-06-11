#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N, K;
  cin >> N >> K;
  vector<long long> A(N);
  for (int i=0; i<N; i++) cin >> A[i];
  vector<long long> F(N);
  for (int i=0; i<N; i++) cin >> F[i];
  sort(A.begin(), A.end());
  sort(F.begin(), F.end(), greater<long long>());
  long long Mx = 1e12, Mn = 0;
  while(Mn<Mx){
    long long md = (Mx + Mn)/2;
    long long tr = 0;
    for (int i=0; i<N; i++){
      if(A[i]*F[i] > md){
        tr += A[i] - (md / F[i]);
      }
    }
    if(tr>K){
      if (Mn == md){
        cout << Mx << endl;
        return 0;
      }
      Mn = md;
    } else {
      Mx = md;
    }
  }
  cout << Mx << endl;
}
