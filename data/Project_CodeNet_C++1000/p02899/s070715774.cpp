#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin>>N;
  vector<int>vec(N);
  vector<int>v(N);
  for(int X=0;X<N;X++){
    cin>>vec.at(X);
    v.at(vec.at(X)-1)=X+1;
  }
  for(int X=0;X<N;X++){
    if(X==N-1){
      cout<<v.at(X)<<endl;
    }
    else{
      cout<<v.at(X)<<" ";
    }
  }
}
