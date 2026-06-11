#include <iostream>

using namespace std;

int main(){
  string S, T;
  int count=0;
  cin >> S >> T;
  int size = S.size();
  for(int x=0;x<size;x++){
    if(S.at(x)!=T.at(x)){
      count++;
    }
  }
  cout << count;
}