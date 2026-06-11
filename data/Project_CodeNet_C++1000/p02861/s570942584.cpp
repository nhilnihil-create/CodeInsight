#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;cin>>N;
  vector<int>A(N);
  vector<int>B(N);
  for(int X=0;X<N;X++){
    cin>>A[X]>>B[X];
  }
  long double K=0;
  for(int X=0;X<N-1;X++){
    for(int Y=X+1;Y<N;Y++){
      K+=sqrt((A[X]-A[Y])*(A[X]-A[Y])+(B[X]-B[Y])*(B[X]-B[Y]));
    }
  }
  cout<<fixed<<setprecision(10)<<K*2/N<<endl;
}