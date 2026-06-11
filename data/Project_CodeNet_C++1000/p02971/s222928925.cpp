#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N;
  cin>>N;
  vector<int>vec(N);
  vector<int>v(N);
  for(int X=0;X<N;X++){
    cin>>vec.at(X);
    v.at(X)=vec.at(X);
  }
  sort(v.begin(),v.end());
  for(int X=0;X<N;X++){
    if(vec.at(X)==v.at(N-1)){
      cout<<v.at(N-2)<<endl;
    }
    else{
      cout<<v.at(N-1)<<endl;
    }
  }
}