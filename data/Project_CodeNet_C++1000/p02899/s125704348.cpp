#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin>>N;
  vector<int>vec(N);
  vector<int>v(N);
  for(int X=0;X<N;X++){
    cin>>vec[X];
    v[vec[X]-1]=X+1;
  }
  for(int X=0;X<N;X++){
    if(X==N-1){
      cout<<v[X]<<endl;
    }
    else{
      cout<<v[X]<<" ";
    }
  }
}