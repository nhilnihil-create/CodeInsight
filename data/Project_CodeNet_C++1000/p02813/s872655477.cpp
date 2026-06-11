#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;cin>>N;
  vector<int>P(N),Q(N),K(N);
  for(int X=0;X<N;X++){
    cin>>P[X];
  }
  for(int X=0;X<N;X++){
    cin>>Q[X];
  }
  for(int X=0;X<N;X++){
    K[X]=X+1;
  }
  int A,B;
  int M=0;
  do{
    M++;
    if(K==P){
      A=M;
    }
    if(K==Q){
      B=M;
    }
  } while (next_permutation(K.begin(), K.end()));
  cout<<abs(A-B)<<endl;
}