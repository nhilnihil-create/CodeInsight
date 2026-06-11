#include <iostream>
 
using namespace std;
 
int main(){
  int N;
  long long ans=0, c1=0, c2=0, K;
  cin >> N >> K;
  int A[N];
  for(int i=0; i<N; i++){
    cin >> A[i];
  }

  for(int i=0; i<N-1; i++){
    for(int j=i+1; j<N; j++){
      if(A[i] > A[j]){
        c1++;
      }
    }
  }

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(A[i] > A[j]){
        c2++;
      }
    }
  }
  
  long long m1 = K;
  long long m2 = (K * (K - 1) / 2) % 1000000007;
  ans = (c1 * m1 + c2 * m2) % 1000000007;

  cout << ans << endl;
}
