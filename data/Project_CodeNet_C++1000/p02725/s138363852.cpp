#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int K,N;
  int S=0;
  cin>>K>>N;
  vector<int>A(N);
  vector<int>B(N);
  for(int X=0;X<N;X++){
    cin>>A[X];
    if(0<X){
      B[X-1]=abs(A[X]-A[X-1]);
    }
  }
  B[N-1]=K-A[N-1]+A[0];
  sort(B.begin(),B.end());
  cout<<K-B[N-1]<<endl;
}
