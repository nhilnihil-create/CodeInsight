#include <bits/stdc++.h>
using namespace std;

int main(){
  string T;
  cin >> T;
  int C=T.size();
  for(int i=0;i<C;i++){
    if(T.at(i)=='?'){
      T.at(i)='D';
    }
    cout << T.at(i);
    if(i==C-1){
      cout << endl;
    }
  }
}