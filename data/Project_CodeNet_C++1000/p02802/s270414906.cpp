#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M;cin>>N>>M;vector<bool>V(N,true);vector<int>F(N);int P=0;int A=0;
  for(int X=0;X<M;X++){
    int L;string S;cin>>L>>S;
    if(V[L-1]&&S=="WA"){
      P++;F[L-1]++;
    }
    if(V[L-1]&&S=="AC"){
      A++;V[L-1]=false;
    }
  }
  for(int X=0;X<N;X++){
    if(V[X])P-=F[X];
  }
  cout<<A<<" "<<P<<endl;
}
