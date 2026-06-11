#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int>vec(N);
  for(int X=0;X<N;X++){
    cin>>vec.at(X);
  }
  sort(vec.begin(), vec.end());
  double M=(vec.at(0));
  for(int X=1;X<N;X++){
    M=(M+vec.at(X))/2;
  }
  cout<<M<<endl;
}