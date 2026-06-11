#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int M=0;
  int L=0;
  cin>>N;
  vector<int>vec(N);
  for(int X=0;X<N;X++){
    cin>>vec.at(X);
    if(M<vec.at(X)){
      L=M;
      M=vec.at(X);
    }
    else if(L<vec.at(X)){
      L=vec.at(X);
    }
  }
  for(int X=0;X<N;X++){
    if(vec.at(X)==M){
      cout<<L<<endl;
    }
    else{
      cout<<M<<endl;
    }
  }
}