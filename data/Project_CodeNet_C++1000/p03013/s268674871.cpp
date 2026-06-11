#include <bits/stdc++.h>
using namespace std;
 
int main() {
int N,M;
  cin >> N >> M;
  vector<int> A(M);
  vector<int> C(N,0);
  for(int a = 0;a < M;a++){
    cin >> A[a];
   C[A[a]] = 1; 
  }
  vector<long long> B(N + 10);
  B[N] = 1;
    for(int a = N-1;a >= 0;a--){
    if(C[a] == 1){
      B[a] = 0;
    }else{
     B[a] = B[a+1]+B[a+2];
      B[a] %= 1000000007;
    }
  }
  cout << B[0] << endl;
}
