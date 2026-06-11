#include <bits/stdc++.h>
using namespace std;
 
int main () {
  long long O=1000000007;
  long long N,K;cin>>N>>K;
  vector<int>A(N);
  vector<int>B(N*2);
  for(int X=0;X<N;X++){
    cin>>A[X];
    B[X]=A[X];
    B[N+X]=A[X];
  }
  long long M=0;
  for(int X=0;X<N-1;X++){
    for(int Y=X+1;Y<N;Y++){
      if(A[X]>A[Y]){
        M++;
        M%=1000000007;
      }
    }
  }
  long long H=0;
  for(int X=0;X<N;X++){
    for(int Y=N;Y<N*2;Y++){
      if(B[X]>B[Y]){
        H++;
        H%=1000000007;
      }
    }
  }
  cout<<((M*K)%O+(H*(K*(K-1)/2%O))%O)%O<<endl;
}
