#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int M=0;
  int L=0;
  cin>>N;
  vector<long long>vec(N);
  for(int X=0;X<N;X++){
    cin>>vec.at(X);
    if(X>0 && vec.at(X)<=vec.at(X-1)){
      M++;
    }
    else if(X>0 && vec.at(X)>vec.at(X-1)){
      if(M>=L){
        L=M;
        M=0;
      }
      else{
        M=0;
      }
    }
  }
  cout<<max(L,M)<<endl;
}