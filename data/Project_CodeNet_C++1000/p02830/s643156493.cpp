#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string S,T;
  cin >> N >> S >> T;
  for(int i=0;i<2*N;i++){
    if(i%2==0){
      cout << S.at(i/2);
    }
    else{
      cout << T.at(i/2);
    }
  }
  cout << endl;
}
  