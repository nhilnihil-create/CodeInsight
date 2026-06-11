#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  cin>>N>>K;
  string S;
  cin>>S;
  int Z=0;
  for(int i=0;i<N-1;i++){
    if(S[i]==S[i+1]){
      Z++;
    }
  }
  cout<<min(N-1,Z+2*K)<<endl;
}