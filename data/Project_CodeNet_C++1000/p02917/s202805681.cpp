#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  long long M=0;
  cin>>N;
  vector<int>vec(N-1);
  for(int X=0;X<N;X++){
    if(X<N-1){
      cin>>vec.at(X);
    }
    if(X>0 && X<N-1){
      M+=min(vec.at(X),vec.at(X-1));
    }
    else if(X==0){
      M+=vec.at(X);
    }
    else{
      M+=vec.at(N-2);
    }
  }
  cout<<M<<endl;
}