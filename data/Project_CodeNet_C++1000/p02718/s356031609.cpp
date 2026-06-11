#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M;
  int S=0;
  long double L=0;
  cin>>N>>M;
  vector<int>vec(N);
  for(int X=0;X<N;X++){
    cin>>vec.at(X);
    L+=vec.at(X);
  }
  sort(vec.begin(),vec.end());
  for(int X=N-1;X>=0;X--){
    if(vec.at(X)>=L/(M*4)){
      S++;
    }
    else{
      break;
    }
  }
  if(S>=M){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}
