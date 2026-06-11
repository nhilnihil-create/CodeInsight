#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M;
  int F=0;
  cin>>N>>M;
  vector<long long>vec(N);
  vector<bool>ve(N,true);
  vector<vector<int>> v(M, vector<int>(2));
  for(int X=0;X<N;X++){
    cin>>vec.at(X);
  }
  for(int X=0;X<M;X++){
    for(int Y=0;Y<2;Y++){
      cin>>v.at(X).at(Y);
    }
  }
  for(int X=0;X<M;X++){
    if(vec.at(v.at(X).at(0)-1)>=vec.at(v.at(X).at(1)-1)){
      ve.at(v.at(X).at(1)-1)=false;
    }
    if(vec.at(v.at(X).at(0)-1)<=vec.at(v.at(X).at(1)-1)){
      ve.at(v.at(X).at(0)-1)=false;
    }
  }
  for(int X=0;X<N;X++){
    if(ve.at(X)==true){
      F++;
    }
  }
  cout<<F<<endl;
}