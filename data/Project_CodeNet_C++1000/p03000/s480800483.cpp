#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,Y,X;
  int U=0;
  cin>>N>>Y;
  vector<int>vec(N);
  for(X=0;X<N;X++){
    cin>>vec[X];
    if(U+vec[X]<=Y){
      U=U+vec[X];
    }
    else{
      break;
    }
  }
  cout<<X+1<<endl;
}
