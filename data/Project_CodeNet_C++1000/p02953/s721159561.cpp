#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  bool L=true;
  cin>>N;
  vector<long long>vec(N);
  for(int X=0;X<N;X++){
    cin>>vec.at(X);
  }
  for(int X=N-1;X>=0;X--){
    if(X<N-1 && vec.at(X+1)<vec.at(X)){
      if(vec.at(X)-1!=vec.at(X+1)){
        L=false;
      }
      else{
        vec.at(X)--;
      }
    }
  }
  if(L==true){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}